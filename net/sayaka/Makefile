# $NetBSD: Makefile,v 1.48 2024/02/23 08:53:03 tsutsui Exp $

DISTNAME=	sayaka-3.7.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=isaki68k/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/isaki68k/sayaka
COMMENT=	Terminal specific Twitter client
LICENSE=	modified-bsd AND mit

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config
BUILD_TARGET=		sayaka
MAKE_FLAGS+=		-DRELEASE

USE_CXX_FEATURES+=	c++17

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sayaka ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../security/mbedtls/buildlink3.mk"
.include "../../www/wslay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
