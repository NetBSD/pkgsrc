# $NetBSD: Makefile,v 1.4.2.1 2012/04/11 18:26:36 spz Exp $

.include "../../net/samba/Makefile.mirrors"

DISTNAME=		samba-${VERSION}
PKGREVISION=		10
CATEGORIES=		net
MASTER_SITES=		${SAMBA_MIRRORS:=old-versions/}

.include "Makefile.patches"

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		SMB/CIFS protocol server suite
LICENSE=		gnu-gpl-v2

VERSION=		3.0.37
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
SAMBA_LIBDIR?=		${PREFIX}/lib/samba
SAMBA_LOCKDIR?=		${SAMBA_VARDIR}/run/samba
SAMBA_LOGDIR?=		${SAMBA_VARDIR}/log
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

CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR:Q}
CONFIGURE_ARGS+=	--with-libdir=${SAMBA_LIBDIR:Q}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR:Q}
CONFIGURE_ARGS+=	--with-logfilebase=${SAMBA_LOGDIR:Q}
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

.include "../../net/samba33/options.mk"

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
SUBST_SED.paths+=	-e 's,@AWK@,${AWK},g' -e 's,@CAT@,${CAT},g'
SUBST_SED.paths+=	-e 's,@MKTEMP@,${MKTEMP},g' -e 's,@RM@,${RM},g'
SUBST_SED.paths+=	-e 's,@PWD_MKDB@,${PWD_MKDB},g' -e 's,@SH@,${SH},g'
SUBST_STAGE.paths=	post-patch

# Get the shared library major and minors for the installed shared
# libraries.  We'll need these to create the versioned symlinks for
# the shared libraries because samba Makefile doesn't do it on its
# own.
#
SAMBA_LIBS=		smbclient msrpc smbsharemodes addns

.PHONY: install-samba-lib-symlinks
.for l in ${SAMBA_LIBS}
.  for NUM in MAJOR MINOR
LIB${NUM}_cmd.${l}=	${AWK} -F= '/^LIB${l:tu}_${NUM}/ { print $$2; }' \
				${WRKSRC:Q}/Makefile.in
LIB${NUM}.${l}=		${LIB${NUM}_cmd.${l}:sh}
PLIST_SUBST+=		LIB${NUM}.${l}=${LIB${NUM}.${l}}
.  endfor

SAMBA_VERSIONS.${l}=	${LIBMAJOR.${l}} ${LIBMAJOR.${l}}.${LIBMINOR.${l}}

.PHONY: install-samba-lib-symlinks-${l}
install-samba-lib-symlinks: install-samba-lib-symlinks-${l}
install-samba-lib-symlinks-${l}:
	for v in ${SAMBA_VERSIONS.${l}}; do				\
		cd ${DESTDIR}${SAMBA_LIBDIR} &&				\
			rm -f lib${l}.so.$$v &&				\
			ln -s lib${l}.so lib${l}.so.$$v;		\
	done
.endfor

post-extract:
	${CP} ${FILESDIR}/adduser.sh ${FILESDIR}/deluser.sh ${WRKDIR}

post-install: install-samba-lib-symlinks
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/js
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/include
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/images
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/ja/js
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/tr/include
	${RMDIR} ${DESTDIR}${PREFIX}/share/samba/swat/lang/tr/js
	for d in idmap pdb rpc; do					\
		${RMDIR} ${DESTDIR}${SAMBA_LIBDIR}/$$d;			\
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
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/include/libmsrpc.h \
		${DESTDIR}${PREFIX}/include/libsmbclient.h

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
