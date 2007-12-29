# $NetBSD: Makefile,v 1.11 2007/12/29 09:50:14 wiz Exp $
#

DISTNAME=		circuslinux-1.0.3
PKGREVISION=		7
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.billsgames.com/unix/x/circus-linux/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.newbreedsoftware.com/circus-linux/
COMMENT=		Clone of the Atari 2600 game "Circus Atari"

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-joystick
CONFIGURE_ENV+=		TARGET_DEF=LINUX

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
