# $NetBSD: Makefile,v 1.2 2012/03/16 04:31:15 obache Exp $
#

DISTNAME=	aubio-0.3.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://aubio.org/pub/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://aubio.org/
COMMENT=	Extracting annotations from audio signals
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	aubio.pc.in

# Python related variables:
PY_PATCHPLIST=			yes
PYTHON_PATCH_SCRIPTS=	python/aubiocut python/aubiopitch

.include "options.mk"

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
