# $NetBSD: Makefile,v 1.23 2025/01/06 21:49:05 ktnb Exp $
#

DISTNAME=	dega-1.07
PKGREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	http://www.emulinks.de/emus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.finalburn.com/dega/
COMMENT=	Sega Game Gear, Sega Mark III and Sega Master System emulator

TOOL_DEPENDS+=	nasm>=0.98:../../devel/nasm

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# Uses i386 assembly code
ONLY_FOR_PLATFORM=	*-*-i386

INSTALLATION_DIRS=	bin

LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dega ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
