# $NetBSD: Makefile,v 1.69 2004/10/03 00:13:26 tv Exp $
#

DISTNAME=	cvsync-0.24.16
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/

MAINTAINER=	gehenna@NetBSD.org
HOMEPAGE=	http://www.cvsync.org/
COMMENT=	Portable incremental cvs repository syncer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
INSTALLATION_DIRS=	bin man/man1

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}
MAKE_ENV+=	MANMODE=${MANMODE}
MAKE_ENV+=	PTHREAD_TYPE=${PTHREAD_TYPE}
MAKE_ENV+=	PTHREAD_PREFIX=${BUILDLINK_PREFIX.pthread}

EGDIR=		${PREFIX}/share/examples/cvsync
CONF_FILES+=	${EGDIR}/cvsync.conf ${PKG_SYSCONFDIR}/cvsync.conf

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.cvsync
.ifdef ${OPSYS} == "AIX" || ${OPSYS} == "BSDOS" || ${OPSYS} == "Darwin" || \
	${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_OPTIONS.cvsync?=	openssl
PKG_SUPPORTED_OPTIONS=	libgcrypt mhash openssl
.else
PKG_OPTIONS.cvsync?=	native
PKG_SUPPORTED_OPTIONS=	libgcrypt mhash native openssl
.endif
.include "../../mk/bsd.options.mk"

###
### Hash type
###
.if !empty(PKG_OPTIONS:Mlibgcrypt)
MAKE_ENV+=	HASH_TYPE="libgcyprt"
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
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsync.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-FreeBSD.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-NetBSD.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-OpenBSD.conf ${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
