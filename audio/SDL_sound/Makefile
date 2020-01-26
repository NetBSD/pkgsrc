# $NetBSD: Makefile,v 1.32 2020/01/26 17:30:41 rillig Exp $
#

DISTNAME=		SDL_sound-1.0.3
PKGREVISION=		6
CATEGORIES=		audio
MASTER_SITES=		http://icculus.org/SDL_sound/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://icculus.org/SDL_sound/
COMMENT=		SDL library to handle the decoding of different file formats
LICENSE=		gnu-lgpl-v2.1

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
