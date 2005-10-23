# $NetBSD: Makefile,v 1.11 2005/10/23 14:34:41 rillig Exp $
#

DISTNAME=	dega-1.07
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.emulinks.de/emus/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.finalburn.com/dega/
COMMENT=	Sega Game Gear, Sega Mark III and Sega Master System emulator

BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

USE_TOOLS+=	gmake

# Uses i386 assembly code
ONLY_FOR_PLATFORM=	*-*-i386

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dega ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
