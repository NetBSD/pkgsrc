# $NetBSD: Makefile,v 1.1.1.1 2004/08/06 16:52:56 drochner Exp $
#

DISTNAME=		circuslinux-1.0.3
CATEGORIES=		games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/circus-linux/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.newbreedsoftware.com/circus-linux/
COMMENT=		Clone of the Atari 2600 game "Circus Atari"

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-joystick
CONFIGURE_ENV+=		TARGET_DEF=LINUX

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
