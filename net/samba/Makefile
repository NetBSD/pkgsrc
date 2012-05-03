# $NetBSD: Makefile,v 1.217.2.2 2012/05/03 19:35:43 tron Exp $

.include "../../net/samba/Makefile.mirrors"

DISTNAME=	samba-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${SAMBA_MIRRORS:=stable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.samba.org/
COMMENT=	SMB/CIFS protocol server suite
LICENSE=	gnu-gpl-v3

VERSION=	3.6.5
CONFLICTS+=	ja-samba-[0-9]* pam-smbpass-[0-9]* tdb-[0-9]* winbind-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

FILESDIR=		${PKGDIR}/../../net/samba/files
DESCR_SRC=		${PKGDIR}/../../net/samba/DESCR
MESSAGE_SRC=		${PKGDIR}/../../net/samba/MESSAGE
WRKSRC=			${WRKDIR}/${DISTNAME}/source3
BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	samba
SAMBA_ETCDIR?=		${PKG_SYSCONFDIR}
SAMBA_LIBDIR?=		${PREFIX}/lib
SAMBA_LOCKDIR?=		${SAMBA_VARDIR}/run/samba
SAMBA_LOGDIR?=		${SAMBA_VARDIR}/log
SAMBA_MODULESDIR?=	${SAMBA_LIBDIR}/samba
SAMBA_PIDDIR?=		${SAMBA_VARDIR}/run
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private
SAMBA_STATEDIR?=	${SAMBA_VARDIR}/db/samba
SAMBA_VARDIR?=		${VARBASE}
WINBINDD_RCD_SCRIPT=	# empty

FILES_SUBST+=		SAMBA_ETCDIR=${SAMBA_ETCDIR}
FILES_SUBST+=		SAMBA_LOCKDIR=${SAMBA_LOCKDIR}
FILES_SUBST+=		SAMBA_LOGDIR=${SAMBA_LOGDIR}
FILES_SUBST+=		SAMBA_PIDDIR=${SAMBA_PIDDIR}
FILES_SUBST+=		SAMBA_PRIVATE=${SAMBA_PRIVATE:Q}
FILES_SUBST+=		SAMBA_STATEDIR=${SAMBA_STATEDIR}
FILES_SUBST+=		SAMBA_VARDIR=${SAMBA_VARDIR}
FILES_SUBST+=		WINBINDD_RCD_SCRIPT=${WINBINDD_RCD_SCRIPT:Q}

# mktemp is useful for the replacement adduser script, but don't require
# a full dependency since it's not actually needed by samba.
USE_TOOLS+=		gmake mktemp perl:run
REPLACE_PERL=		script/findsmb.in

BROKEN_GETTEXT_DETECTION=yes
USE_GNU_READLINE=	yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBDIR=	${SAMBA_LIBDIR}
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}
CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-logfilebase=${SAMBA_LOGDIR}
CONFIGURE_ARGS+=	--with-modulesdir=${SAMBA_MODULESDIR}
CONFIGURE_ARGS+=	--with-piddir=${SAMBA_PIDDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE:Q}
CONFIGURE_ARGS+=	--with-statedir=${SAMBA_STATEDIR}
CONFIGURE_ARGS+=	--localstatedir=${SAMBA_VARDIR}
CONFIGURE_ARGS+=	--with-mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-swatdir=${PREFIX}/share/samba/swat
#
# Explicitly disable samba4 merged-build option which is broken.
#
CONFIGURE_ARGS+=	--enable-merged-build=no

.include "../../net/samba/options.mk"

PLIST_VARS+=		macosx

.if ${OPSYS} == "Darwin"
PLIST.macosx=		yes
.endif

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SUBST+=	LIBEXT=dylib
SAMBA_LIBEXT=	dylib
.else
PLIST_SUBST+=	LIBEXT=so
SAMBA_LIBEXT=	so
.endif

.if !defined(PWD_MKDB)
PWD_MKDB!=	${TYPE} pwd_mkdb 2>&1 | \
		${AWK} '/not found/ { print "pwd_mkdb"; exit } { print $$3 }'
MAKEFLAGS+=	PWD_MKDB=${PWD_MKDB:Q}
.endif
FILES_SUBST+=	MKTEMP=${MKTEMP:Q}
FILES_SUBST+=	PWD_MKDB=${PWD_MKDB:Q}

.if ${OPSYS} == "NetBSD"
.  if !empty(PKG_OPTIONS:Mwinbind)
# Install a /usr/lib/nss_winbind.so.0 -> ${PREFIX}/lib/nss_winbind.so.0 symlink
INSTALL_TEMPLATES+=	INSTALL.nss_winbind
.  endif
.endif

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}
CONF_FILES=	${PREFIX}/${EGDIR}/smb.conf.default ${SAMBA_ETCDIR}/smb.conf
MAKE_DIRS=	${SAMBA_VARDIR} ${SAMBA_LOGDIR} ${SAMBA_PIDDIR}
OWN_DIRS=	${SAMBA_ETCDIR} ${SAMBA_LOCKDIR} ${SAMBA_STATEDIR}
OWN_DIRS_PERMS=	${SAMBA_PRIVATE} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
RCD_SCRIPTS+=	samba nmbd smbd ${WINBINDD_RCD_SCRIPT}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_FILES.paths=	${WRKDIR}/adduser.sh ${WRKDIR}/deluser.sh
SUBST_STAGE.paths=	post-patch
SUBST_SED.paths+=	-e 's,@AWK@,${AWK},g'
SUBST_SED.paths+=	-e 's,@CAT@,${CAT},g'
SUBST_SED.paths+=	-e 's,@MKTEMP@,${MKTEMP},g'
SUBST_SED.paths+=	-e 's,@RM@,${RM},g'
SUBST_SED.paths+=	-e 's,@PWD_MKDB@,${PWD_MKDB},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'

post-extract:
	${CP} ${FILESDIR}/adduser.sh ${FILESDIR}/deluser.sh ${WRKDIR}

post-install:
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/js
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/include
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/images
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/js
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/tr/include
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/tr/js
	${RMDIR} ${DESTDIR}${SAMBA_MODULESDIR}/gpext
	${RMDIR} ${DESTDIR}${SAMBA_MODULESDIR}/nss_info
	${RMDIR} ${DESTDIR}${SAMBA_MODULESDIR}/pdb
	${RMDIR} ${DESTDIR}${SAMBA_MODULESDIR}/perfcount
	set -e ; cd ${WRKDIR}/${DISTNAME}/docs/registry; for f in *.reg; do \
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/${DOCDIR}/$${f}; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/adduser.sh \
		${DESTDIR}${PREFIX}/${EGDIR}/adduser.sh
	${INSTALL_SCRIPT} ${WRKDIR}/deluser.sh \
		${DESTDIR}${PREFIX}/${EGDIR}/deluser.sh
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/LDAP/samba.schema \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/smb.conf.default \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script/mknissmbpasswd.sh \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script/mknissmbpwdtbl.sh \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/script/updatesmbpasswd.sh \
		${DESTDIR}${PREFIX}/${EGDIR}
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/include/*.h

.if ${OPSYS} == "Linux"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
