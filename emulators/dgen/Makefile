# $NetBSD: Makefile,v 1.2 2004/01/22 08:36:04 grant Exp $
#

DISTNAME=	dgen-sdl-1.23
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
USE_BUILDLINK2=	yes

CONFIGURE_ARGS+=	--with-extra-opt

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
