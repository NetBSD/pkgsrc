# $NetBSD: Makefile,v 1.2 2005/07/14 12:49:34 adam Exp $

DISTNAME=	fluidsynth-1.0.6
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/fluid/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.fluidsynth.org/
COMMENT=	Software synthesizer based on SoundFont2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	fluidsynth.pc.in

CFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
LDFLAGS+=		${LIBOSSAUDIO}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
