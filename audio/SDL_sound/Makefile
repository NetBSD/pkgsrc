# $NetBSD: Makefile,v 1.16 2006/06/12 16:28:05 wiz Exp $
#

DISTNAME=		SDL_sound-1.0.1
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		http://icculus.org/SDL_sound/downloads/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://icculus.org/SDL_sound/
COMMENT=		SDL library to handle the decoding of different file formats

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
