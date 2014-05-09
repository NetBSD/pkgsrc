# $NetBSD: Makefile,v 1.7 2014/05/09 07:36:53 wiz Exp $

DISTNAME=	aubio-0.3.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://aubio.org/pub/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://aubio.org/
COMMENT=	Extracting annotations from audio signals
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	aubio.pc.in

# Python related variables:
PY_PATCHPLIST=			yes
REPLACE_PYTHON=	python/aubiocut python/aubiopitch
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3.2

.include "options.mk"

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
