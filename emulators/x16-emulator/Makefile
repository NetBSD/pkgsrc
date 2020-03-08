# $NetBSD: Makefile,v 1.2 2020/03/08 16:49:29 wiz Exp $

DISTNAME=	x16-emulator-35
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=commanderx16/}
GITHUB_PROJECT=	x16-emulator
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://commanderx16.com/
COMMENT=	Emulator for the Commander X16 computer system
LICENSE=	2-clause-bsd

DEPENDS+=	x16-rom-35{,nb*}:../../emulators/x16-rom
MAKE_ENV+=	ROM_RELATIVE_PATH=../share/x16/

USE_TOOLS+=	gmake

INSTALLATION_DIRS+= bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x16emu ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
