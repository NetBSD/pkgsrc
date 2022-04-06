# $NetBSD: Makefile,v 1.1 2022/04/06 16:32:21 nia Exp $

DISTNAME=	zam-plugins-3.14
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=zamaudio/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.zamaudio.com/?p=976
COMMENT=	Collection of LADSPA/LV2/VST/JACK audio plugins
LICENSE=	gnu-gpl-v2

GITHUB_SUBMODULES=	\
	DISTRHO DPF 08669d1bc30c6e971fde800eade4ca40104ba8b2 dpf

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

REPLACE_SH+=	dpf/utils/generate-ttl.sh

.include "options.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
