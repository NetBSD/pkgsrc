# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:43 tv Exp $
#

DISTNAME=		circuslinux-1.0.3
PKGREVISION=	1
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
