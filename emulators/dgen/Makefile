# $NetBSD: Makefile,v 1.34 2024/02/17 21:23:57 nia Exp $
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
# Seems broken, at least with latest NASM version:
# -DNASM_STACK_NOEXEC: fatal: more than one input file specified: -f
CONFIGURE_ARGS+=	--disable-asm
.endif

.if !empty(MACHINE_ARCH:Mearm*)
CONFIGURE_ARGS+=	--without-cyclone
.endif

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

BUILDLINK_TRANSFORM+=	rm:-mpentium
BUILDLINK_TRANSFORM+=	rm:-march=pentium
BUILDLINK_TRANSFORM+=	rm:-fno-rtti

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
