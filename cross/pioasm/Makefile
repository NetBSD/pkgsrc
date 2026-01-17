# $NetBSD: Makefile,v 1.2 2026/01/17 12:22:29 tnn Exp $

DISTNAME=	pico-sdk-2.2.0
PKGNAME=	${DISTNAME:S/pico-sdk/pioasm/}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=raspberrypi/}
GITHUB_PROJECT=	pico-sdk
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/raspberrypi/pico-sdk/
COMMENT=	Raspberry Pi Pico PIO assembler
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DPIOASM_VERSION_STRING=${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${DISTNAME}/tools/pioasm

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
