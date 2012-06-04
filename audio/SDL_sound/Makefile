# $NetBSD: Makefile,v 1.28 2012/06/04 09:29:53 wiz Exp $
#

DISTNAME=		SDL_sound-1.0.3
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		http://icculus.org/SDL_sound/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://icculus.org/SDL_sound/
COMMENT=		SDL library to handle the decoding of different file formats

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
