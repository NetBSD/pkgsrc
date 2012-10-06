# $NetBSD: Makefile,v 1.17 2012/10/06 11:54:39 asau Exp $
#

DISTNAME=		freedroid-1.0.2
PKGREVISION=		12
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=freedroid/}

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://freedroid.sourceforge.net/
COMMENT=		Clone of the C64 game Paradroid

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink3.mk"
# XXX: vorbis support is broken
#.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
