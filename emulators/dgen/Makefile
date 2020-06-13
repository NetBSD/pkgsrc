# $NetBSD: Makefile,v 1.32 2020/06/13 10:29:48 nia Exp $
#

DISTNAME=	dgen-sdl-1.33
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dgen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dgen.sourceforge.net/
COMMENT=	Genesis/Megadrive emulator for Unix platforms

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

.if !empty(MACHINE_ARCH:Mearm*)
CONFIGURE_ARGS+=	--without-cyclone
.endif

USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	rm:-mpentium
BUILDLINK_TRANSFORM+=	rm:-march=pentium
BUILDLINK_TRANSFORM+=	rm:-fno-rtti

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
