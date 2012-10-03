# $NetBSD: Makefile,v 1.20 2012/10/03 12:55:11 asau Exp $
#

DISTNAME=	dgen-sdl-1.28
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dgen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dgen.sourceforge.net/
COMMENT=	Genesis/Megadrive emulator for Unix platforms

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-extra-opt

BUILDLINK_TRANSFORM+=	rm:-mpentium
BUILDLINK_TRANSFORM+=	rm:-march=pentium
BUILDLINK_TRANSFORM+=	rm:-fno-rtti

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-[34]*)
BUILDLINK_TRANSFORM+=	'opt:-m\(align-loops.*\):-f\1'
BUILDLINK_TRANSFORM+=	'opt:-m\(align-jumps.*\):-f\1'
BUILDLINK_TRANSFORM+=	'opt:-m\(align-functions.*\):-f\1'
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
