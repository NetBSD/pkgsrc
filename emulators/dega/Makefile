# $NetBSD: Makefile,v 1.1.1.1 2003/09/14 19:10:01 jmmv Exp $
#

DISTNAME=	dega-1.07
CATEGORIES=	emulators
MASTER_SITES=	http://www.emulinks.de/emus/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.finalburn.com/dega/
COMMENT=	Sega Game Gear, Sega Mark III and Sega Master System emulator

BUILD_DEPENDS=	nasm>=0.98:../../devel/nasm

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dega ${PREFIX}/bin

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
