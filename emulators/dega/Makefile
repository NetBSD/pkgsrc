# $NetBSD: Makefile,v 1.6 2005/03/27 15:43:33 wiz Exp $
#

DISTNAME=	dega-1.07
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.emulinks.de/emus/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.finalburn.com/dega/
COMMENT=	Sega Game Gear, Sega Mark III and Sega Master System emulator

BUILD_DEPENDS=	nasm>=0.98:../../devel/nasm

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

# Uses i386 assembly code
ONLY_FOR_PLATFORM=	*-*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dega ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
