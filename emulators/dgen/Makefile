# $NetBSD: Makefile,v 1.5 2005/02/20 16:34:39 xtraeme Exp $
#

DISTNAME=	dgen-sdl-1.23
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.pknet.com/~joe/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.pknet.com/~joe/dgen-sdl.html
COMMENT=	Genesis/Megadrive emulator for Unix platforms

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_X11=	yes
USE_BUILDLINK3=	yes

CONFIGURE_ARGS+=	--with-extra-opt

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	configure
SUBST_SED.config=	-e "s|\-malign-loops|\-falign-loops|g" \
			-e "s|\-malign-jumps|\-falign-jumps|g" \
			-e "s|\-malign-functions|\-falign-functions|g" \
			-e "s|\-mpentium||g" \
			-e "s|\-march=pentium||g" \
			-e "s|\-fno-rtti||g"
SUBST_MESSAGE.config=	"Removing outdated compilation flags."

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
