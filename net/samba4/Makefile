# $NetBSD: Makefile,v 1.50 2018/11/14 22:22:14 kleink Exp $

DISTNAME=	samba-${VERSION}
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	http://download.samba.org/pub/samba/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.samba.org/
COMMENT=	SMB/CIFS protocol server suite
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

VERSION=	4.6.8
CONFLICTS+=	ja-samba-[0-9]* tdb-[0-9]* winbind-[0-9]*

GCC_REQD+=	4.4
BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-iso8601-[0-9]*:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

SMB_LIB?=		${PREFIX}/lib

PKG_SYSCONFSUBDIR=	samba
SMB_SHAREDSTATE?=	${PREFIX}/com
SMB_LOCALSTATE?=	${VARBASE}
SMB_INFO?=		${PREFIX}/info
SMB_MAN?=		${PREFIX}/${PKGMANDIR}
SMB_STATE?=		${VARBASE}/run
SMB_PRIVATE?=		${SMB_LIB}/samba/private
SMB_PID?=		${VARBASE}/run
SMB_CACHE?=		${VARBASE}/run
SMB_LOCK?=		${VARBASE}/run
SMB_LOGFILEBASE?=	${VARBASE}/log
SMB_SOCKETS?=		${VARBASE}/run
SMB_MODULES?=		${SMB_LIB}/samba
SMB_PRIVATELIB?=	${SMB_LIB}/samba/private
SMB_PRIVSOCKETS?=	${VARBASE}/run
SMB_CONFIG?=		${PKG_SYSCONFDIR}
SMB_DATAROOT?=		${PREFIX}/share/samba
SMB_LOCALE?=		${PREFIX}/share/locale
SMB_DOC?=		${PREFIX}/share/doc/samba
SMB_PAMMODULES?=	${SMB_LIB}/samba/security

FILES_SUBST+=		SMB_CONFIG=${SMB_CONFIG}
FILES_SUBST+=		SMB_PID=${SMB_PID}

# mktemp is useful for the replacement adduser script, but don't require
# a full dependency since it's not actually needed by samba.
USE_TOOLS+=		gmake mktemp perl:run pkg-config

REPLACE_PERL=		script/findsmb.in

USE_GNU_ICONV=		yes	# FIXME: something doesn't work on NetBSD
BROKEN_GETTEXT_DETECTION=yes

# Debugging
#CONFIGURE_ARGS+=	-vvv
#CONFIGURE_ARGS+=	--enable-developer
#CONFIGURE_ARGS+=	--fatal-errors

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		XSLTPROC=${FALSE} # suppress generation of man pages
CONFIGURE_ARGS+=	--libdir=${SAMBA_LIB}
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	${WRKSRC}/buildtools/bin/waf
CONFIGURE_ARGS+=	configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${SMB_INFO}
CONFIGURE_ARGS+=	--mandir=${SMB_MAN}
CONFIGURE_ARGS+=	--datarootdir=${SMB_DATAROOT}
CONFIGURE_ARGS+=	--localedir=${SMB_LOCALE}
CONFIGURE_ARGS+=	--docdir=${SMB_DOC}
CONFIGURE_ARGS+=	--with-statedir=${SMB_STATE}
CONFIGURE_ARGS+=	--with-privatedir=${SMB_PRIVATE}
CONFIGURE_ARGS+=	--with-piddir=${SMB_PID}
CONFIGURE_ARGS+=	--with-cachedir=${SMB_CACHE}
CONFIGURE_ARGS+=	--with-lockdir=${SMB_LOCK}
CONFIGURE_ARGS+=	--with-logfilebase=${SMB_LOGFILEBASE}
CONFIGURE_ARGS+=	--with-sockets-dir=${SMB_SOCKETS}
CONFIGURE_ARGS+=	--with-modulesdir=${SMB_MODULES}
CONFIGURE_ARGS+=	--with-privatelibdir=${SMB_PRIVATELIB}
CONFIGURE_ARGS+=	--with-privileged-socket-dir=${SMB_PRIVSOCKETS}
CONFIGURE_ARGS+=	--with-configdir=${SMB_CONFIG}
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}
#CONFIGURE_ARGS+=	--bundled-libraries=com_err
CONFIGURE_ARGS+=	--enable-gnutls
CONFIGURE_ARGS+=	--abi-check-disable
#CONFIGURE_ARGS+=	--bundled-libraries=!crypto,ldb,ntdb,!talloc,tdb,tevent
.if defined(MAKE_JOBS) && !empty(MAKE_JOBS) && !(defined(MAKE_JOBS_SAFE) && !empty(MAKE_JOBS_SAFE:M[nN][oO]))
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS}
.else
CONFIGURE_ARGS+=	--jobs=1
.endif

# Depends on ncurses, explicitly disable for now.
CONFIGURE_ARGS+=	--without-regedit

# for winbind option build.
.if ${OPSYS} != "SunOS"
LDFLAGS+=		-Wl,--allow-shlib-undefined
.endif
LDFLAGS+=		${BUILDLINK_LDADD.gettext}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${SMB_PRIVATELIB}

CFLAGS.SunOS+=		-DHAVE_SOLARIS_GETGRENT_R

# workaround https://bugzilla.samba.org/show_bug.cgi?id=12502 for now
CFLAGS.SunOS+=		-DMSG_NOSIGNAL=0

.include "options.mk"

PLIST_VARS+=		macosx

.if ${OPSYS} == "Darwin"
PLIST.macosx=		yes
.endif

.if ${SHLIB_TYPE} == "dylib"
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

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

DOCDIR=		share/doc/${PKGBASE}
EGDIR=		share/examples/${PKGBASE}
CONF_FILES=	${PREFIX}/${EGDIR}/smb.conf.default ${SMB_CONFIG}/smb.conf
OWN_DIRS_PERMS=	${SMB_PRIVATE} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
RCD_SCRIPTS+=	samba nmbd smbd ${WINBINDD_RCD_SCRIPT}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_FILES.paths=	${WRKDIR}/adduser.sh ${WRKDIR}/deluser.sh
SUBST_FILES.paths+=	source3/script/findsmb.in source4/heimdal_build/roken.h
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,@PERL@,${PERL5},g'
SUBST_VARS.paths=	AWK CAT MKTEMP RM PWD_MKDB SH PERL PKG_SYSCONFBASE

SUBST_CLASSES+=		logpath
SUBST_MESSAGE.logpath=	Fixing log path.
SUBST_FILES.logpath=	examples/smb.conf.default
SUBST_STAGE.logpath=	pre-configure
SUBST_SED.logpath+=	-e 's,/usr/local/samba/var/log.%m,${SMB_LOGFILEBASE}/log.%m,g'

.if ${INIT_SYSTEM} == "rc.d"
MESSAGE_SRC=		${PKGDIR}/MESSAGE.rcd
.endif

SMF_INSTANCES=	smbd nmbd

CTF_FILES_SKIP+=	lib/libdcerpc-samr.so.*	# empty

post-extract:
	${CP} ${FILESDIR}/adduser.sh ${FILESDIR}/deluser.sh ${WRKDIR}

post-install:
	set -e ; cd ${WRKSRC}/docs-xml/registry; for f in *.reg; do \
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/${DOCDIR}/$${f}; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/adduser.sh \
		${DESTDIR}${PREFIX}/${EGDIR}/adduser.sh
	${INSTALL_SCRIPT} ${WRKDIR}/deluser.sh \
		${DESTDIR}${PREFIX}/${EGDIR}/deluser.sh
	${INSTALL_DATA} ${WRKSRC}/examples/LDAP/samba.schema \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/smb.conf.default \
		${DESTDIR}${PREFIX}/${EGDIR}

REPLACE_PERL=	pidl/pidl
REPLACE_PYTHON=	buildtools/bin/waf \
		source4/setup/* \
		source4/scripting/bin/* \
		lib/tevent/tevent.py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 4.3.2

.include "../../lang/python/application.mk"

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"

.if ${OPSYS} == "Linux"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
BUILDLINK_API_DEPENDS.talloc+=	talloc>=2.1.9
.include "../../devel/talloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
