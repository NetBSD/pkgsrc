# $NetBSD: Makefile,v 1.11 2025/09/21 18:15:08 wiz Exp $

DISTNAME=	gqrx-2.17.7
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=gqrx-sdr/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gqrx-sdr/gqrx
COMMENT=	Open source software defined radio receiver
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

## Dependencies, aligned with README.md

# GNU Radio:
#   runtime analog audio blocks fft filter pmt
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/gnuradio-digital/buildlink3.mk"
.include "../../ham/gnuradio-network/buildlink3.mk"
#   gr-iqbalance
# (not in pkgsrc) .include "../../ham/gr-iqbalance/buildlink3.mk"

# optional hardware drivers: (\todo Enable or explain why not.)
#.include "../../ham/gnuradio-uhd/buildlink3.mk"
# (not in pkgsrc) .include "../../ham/gr-funcube/buildlink3.mk"
#.include "../../ham/rtl-sdr/buildlink3.mk"
.include "../../ham/hackrf/buildlink3.mk"
# (not in pkgsrc) Airspy
# .include "../../ham/gnuradio-soapy-sdr/buildlink3.mk"

.include "../../ham/gr-osmosdr/buildlink3.mk"

# Upstream says "pulseaudio or portaudio (Linux-only and optional)"
# which doesn't really make sense.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
.include "../../audio/portaudio/buildlink3.mk"
.endif

# qt5 or qt6
.include "options.mk"

.include "../../devel/cmake/build.mk"

# Dependencies not mentioned by upstream:
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
