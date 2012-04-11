# $NetBSD: Makefile,v 1.20.2.1 2012/04/11 18:37:38 spz Exp $

.include "../../net/samba/Makefile.mirrors"

DISTNAME=		samba-${VERSION}
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${SAMBA_MIRRORS:=old-versions/}
PATCH_SITES=		http://www.samba.org/samba/ftp/patches/security/
PATCHFILES=		samba-3.3.16-CVE-2012-1182.patch
PATCH_DIST_STRIP=	 -p2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		SMB/CIFS protocol server suite
LICENSE=		gnu-gpl-v3

VERSION=		3.3.16
CONFLICTS+=		ja-samba-[0-9]* pam-smbpass-[0-9]* tdb-[0-9]*	\
			winbind-[0-9]*
MAKE_JOBS_SAFE=		NO

PKG_DESTDIR_SUPPORT=	user-destdir

FILESDIR=		${PKGDIR}/../samba/files
DESCR_SRC=		${PKGDIR}/../samba/DESCR
MESSAGE_SRC=		${PKGDIR}/../samba/MESSAGE
WRKSRC=			${WRKDIR}/${DISTNAME}/source
GNU_CONFIGURE=		yes
BUILD_DEFS+=		VARBASE
CHECK_WRKREF_SKIP=	*

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	samba
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

FILES_SUBST+=		SAMBA_ETCDIR=${SAMBA_ETCDIR:Q}
FILES_SUBST+=		SAMBA_LOCKDIR=${SAMBA_LOCKDIR:Q}
FILES_SUBST+=		SAMBA_LOGDIR=${SAMBA_LOGDIR:Q}
FILES_SUBST+=		SAMBA_PIDDIR=${SAMBA_PIDDIR:Q}
FILES_SUBST+=		SAMBA_PRIVATE=${SAMBA_PRIVATE:Q}
FILES_SUBST+=		SAMBA_STATEDIR=${SAMBA_STATEDIR:Q}
FILES_SUBST+=		SAMBA_VARDIR=${SAMBA_VARDIR:Q}
FILES_SUBST+=		WINBINDD_RCD_SCRIPT=${WINBINDD_RCD_SCRIPT:Q}

GNU_CONFIGURE_LIBDIR=	${SAMBA_LIBDIR}
CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR:Q}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR:Q}
CONFIGURE_ARGS+=	--with-logfilebase=${SAMBA_LOGDIR:Q}
CONFIGURE_ARGS+=	--with-modulesdir=${SAMBA_MODULESDIR:Q}
CONFIGURE_ARGS+=	--with-piddir=${SAMBA_PIDDIR:Q}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE:Q}
CONFIGURE_ARGS+=	--with-statedir=${SAMBA_STATEDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${SAMBA_VARDIR:Q}

CONFIGURE_ARGS+=	--with-mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--with-swatdir=${PREFIX:Q}/share/samba/swat

.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

USE_GNU_READLINE=	yes
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

.include "options.mk"

# Only Linux supports mount.cifs for mounting a CIFS share into the
# filesystem.
#
PLIST_VARS+=		cifsmount
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-cifsmount
PLIST.cifsmount=	yes
.endif

# mktemp is useful for the replacement adduser script, but don't require
# a full dependency since it's not actually needed by samba.
#
USE_TOOLS+=		mktemp

# findsmb uses perl
#
USE_TOOLS+=		perl:run
REPLACE_PERL=		script/findsmb.in

.if !defined(PWD_MKDB)
PWD_MKDB!=	${TYPE} pwd_mkdb 2>&1 | \
		${AWK} '/not found/ { print "pwd_mkdb"; exit } { print $$3 }'
MAKEFLAGS+=	PWD_MKDB=${PWD_MKDB:Q}
.endif
FILES_SUBST+=	MKTEMP=${MKTEMP:Q}
FILES_SUBST+=	PWD_MKDB=${PWD_MKDB:Q}

DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

CONF_FILES=		${PREFIX}/${EGDIR}/smb.conf.default ${SAMBA_ETCDIR}/smb.conf
MAKE_DIRS=		${SAMBA_VARDIR} ${SAMBA_LOGDIR} ${SAMBA_PIDDIR}
OWN_DIRS=		${SAMBA_ETCDIR} ${SAMBA_LOCKDIR} ${SAMBA_STATEDIR}
OWN_DIRS_PERMS=		${SAMBA_PRIVATE} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
RCD_SCRIPTS+=		samba nmbd smbd ${WINBINDD_RCD_SCRIPT}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/adduser.sh ${WRKDIR}/deluser.sh
SUBST_SED.paths+=	-e 's,@AWK@,${AWK},g'
SUBST_SED.paths+=	-e 's,@CAT@,${CAT},g'
SUBST_SED.paths+=	-e 's,@MKTEMP@,${MKTEMP},g'
SUBST_SED.paths+=	-e 's,@RM@,${RM},g'
SUBST_SED.paths+=	-e 's,@PWD_MKDB@,${PWD_MKDB},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/adduser.sh ${FILESDIR}/deluser.sh ${WRKDIR}

post-install:
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/js
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/include
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/images
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/js
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/tr/include
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/tr/js
	for d in gpext idmap pdb rpc; do				\
		${RMDIR} ${DESTDIR}${SAMBA_MODULESDIR}/$$d;		\
	done
	cd ${WRKDIR}/${DISTNAME}/docs/registry; for f in *.reg; do	\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/${DOCDIR}/$${f}; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/adduser.sh ${DESTDIR}${PREFIX}/${EGDIR}/adduser.sh
	${INSTALL_SCRIPT} ${WRKDIR}/deluser.sh ${DESTDIR}${PREFIX}/${EGDIR}/deluser.sh
	cd ${WRKDIR}/${DISTNAME}/examples; \
		${INSTALL_DATA} LDAP/samba.schema ${DESTDIR}${PREFIX}/${EGDIR}; \
		${INSTALL_DATA} smb.conf.default ${DESTDIR}${PREFIX}/${EGDIR}
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} mknissmbpasswd.sh ${DESTDIR}${PREFIX}/${EGDIR}
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} mknissmbpwdtbl.sh ${DESTDIR}${PREFIX}/${EGDIR}
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} mksmbpasswd.sh ${DESTDIR}${PREFIX}/${EGDIR}
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} updatesmbpasswd.sh ${DESTDIR}${PREFIX}/${EGDIR}
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/include/*.h

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
