# $NetBSD: Makefile,v 1.2 2016/06/19 14:33:11 prlw1 Exp $

DISTNAME=	rubberband-1.8.1
CATEGORIES=	audio
MASTER_SITES=	http://code.breakfastquay.com/attachments/download/34/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://breakfastquay.com/rubberband/
COMMENT=	Audio time-stretching and pitch-shifting library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	rubberband.pc.in

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
