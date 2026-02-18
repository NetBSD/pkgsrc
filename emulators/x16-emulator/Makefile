# $NetBSD: Makefile,v 1.21 2026/02/18 07:57:15 wiz Exp $

DISTNAME=	x16-emulator-48
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=X16Community/}
GITHUB_PROJECT=	x16-emulator
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://commanderx16.com/
COMMENT=	Emulator for the Commander X16 computer system
LICENSE=	2-clause-bsd

DEPENDS+=	x16-rom-48{,nb*}:../../emulators/x16-rom
MAKE_ENV+=	ROM_RELATIVE_PATH=../share/x16/
MAKE_ENV+=	GIT_REV=${GITHUB_TAG}

USE_LANGUAGES=	c99 c++17
USE_TOOLS+=	gmake

INSTALLATION_DIRS+= bin
INSTALLATION_DIRS+= share/x16

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x16emu ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sdcard.img.zip ${DESTDIR}${PREFIX}/share/x16

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
