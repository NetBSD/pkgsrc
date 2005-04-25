# $NetBSD: Makefile,v 1.1.1.1 2005/04/25 13:53:37 adam Exp $

DISTNAME=	fluidsynth-1.0.5
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
