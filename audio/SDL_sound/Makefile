# $NetBSD: Makefile,v 1.5 2003/12/08 14:41:38 wiz Exp $
#

DISTNAME=		SDL_sound-1.0.0
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		http://icculus.org/SDL_sound/downloads/

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://icculus.org/SDL_sound/
COMMENT=		SDL library to handle the decoding of different file formats

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_BUILDLINK2=		YES

.include "../../audio/libmikmod/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
