# $NetBSD: Makefile,v 1.4 2004/10/03 00:14:40 tv Exp $
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

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
