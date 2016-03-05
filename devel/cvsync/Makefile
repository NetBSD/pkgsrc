# $NetBSD: Makefile,v 1.96 2016/03/05 11:28:21 jperkin Exp $
#

DISTNAME=	cvsync-0.24.19
PKGREVISION=	9
CATEGORIES=	devel scm
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cvsync.org/
COMMENT=	Portable incremental cvs repository syncer

USE_TOOLS+=	gmake
USE_LANGUAGES=	c99
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/cvsync

MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} BINMODE=${BINMODE:Q}
MAKE_ENV+=	MANMODE=${MANMODE:Q}
MAKE_ENV+=	PTHREAD_TYPE=${PTHREAD_TYPE:Q}
MAKE_ENV+=	PTHREAD_PREFIX=${BUILDLINK_PREFIX.pthread}
MAKE_ENV+=	CVSYNC_DEFAULT_CONFIG="${PKG_SYSCONFDIR}/cvsync.conf"
MAKE_ENV+=	CVSYNCD_DEFAULT_CONFIG="${PKG_SYSCONFDIR}/cvsyncd.conf"
MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

EGDIR=		${PREFIX}/share/examples/cvsync
CONF_FILES+=	${EGDIR}/cvsync.conf ${PKG_SYSCONFDIR}/cvsync.conf

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.cvsync
PKG_SUPPORTED_OPTIONS=	libgcrypt mhash openssl
.if ${OPSYS} == "AIX" || ${OPSYS} == "BSDOS" || ${OPSYS} == "Darwin" || \
	${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS=	openssl
.else
PKG_SUPPORTED_OPTIONS+=	native
PKG_SUGGESTED_OPTIONS=	native
.endif
.include "../../mk/bsd.options.mk"

###
### Hash type
###
.if !empty(PKG_OPTIONS:Mlibgcrypt)
MAKE_ENV+=	HASH_TYPE="libgcrypt"
.include "../../security/libgcrypt/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mmhash)
MAKE_ENV+=	HASH_TYPE="mhash"
.include "../../security/mhash/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mnative)
MAKE_ENV+=	HASH_TYPE="native"
.elif !empty(PKG_OPTIONS:Mopenssl)
MAKE_ENV+=	HASH_TYPE="openssl"
.include "../../security/openssl/buildlink3.mk"
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/cvsync.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-FreeBSD.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-NetBSD.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-OpenBSD.conf ${DESTDIR}${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
