# $NetBSD: Makefile,v 1.11 2005/12/11 09:40:39 wiz Exp $
#

DISTNAME=	dgen-sdl-1.23
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.pknet.com/~joe/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.pknet.com/~joe/dgen-sdl.html
COMMENT=	Genesis/Megadrive emulator for Unix platforms

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-extra-opt

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	configure
SUBST_SED.config=	-e "s|\-mpentium||g"	    \
			-e "s|\-march=pentium||g"   \
			-e "s|\-fno-rtti||g"
SUBST_MESSAGE.config=	"Removing outdated compilation flags."

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3*)
SUBST_SED.config+=	-e "s|\-malign-loops|\-falign-loops|g"
SUBST_SED.config+=	-e "s|\-malign-jumps|\-falign-jumps|g"
SUBST_SED.config+=	-e "s|\-malign-functions|\-falign-functions|g"
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
