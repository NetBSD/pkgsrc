# $NetBSD: Makefile,v 1.4 2020/08/18 17:57:25 leot Exp $

DISTNAME=	rubberband-1.8.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://breakfastquay.com/files/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://breakfastquay.com/rubberband/
COMMENT=	Audio time-stretching and pitch-shifting library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	rubberband.pc.in

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
