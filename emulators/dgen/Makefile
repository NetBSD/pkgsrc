# $NetBSD: Makefile,v 1.30 2020/03/20 11:57:35 nia Exp $
#

DISTNAME=	dgen-sdl-1.33
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dgen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dgen.sourceforge.net/
COMMENT=	Genesis/Megadrive emulator for Unix platforms

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

PLIST_VARS+=	arm

.if ${MACHINE_CPU:U} == "arm"
PLIST.arm=	yes
.endif

USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-extra-opt

BUILDLINK_TRANSFORM+=	rm:-mpentium
BUILDLINK_TRANSFORM+=	rm:-march=pentium
BUILDLINK_TRANSFORM+=	rm:-fno-rtti

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
