# $NetBSD: Makefile,v 1.136 2025/02/27 13:49:50 adam Exp $

PKGNAME=	gnuradio-core-${VERSION}
COMMENT=	Core part of GNU Radio, all others need this

.include	"Makefile.common"

#CONF_FILES+=	${EGDIR}/gnuradio-runtime.conf	${PKG_SYSCONFDIR}/gnuradio-runtime.conf
#CONF_FILES+=	${EGDIR}/gr-audio-jack.conf	${PKG_SYSCONFDIR}/gr-audio-jack.conf
#CONF_FILES+=	${EGDIR}/gr-audio-portaudio.conf ${PKG_SYSCONFDIR}/gr-audio-portaudio.conf
#CONF_FILES+=	${EGDIR}/gr-audio.conf		${PKG_SYSCONFDIR}/gr-audio.conf

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
#CONF_FILES+=	${EGDIR}/gr-audio-oss.conf	${PKG_SYSCONFDIR}/gr-audio-oss.conf
PLIST_SRC=	${PKGDIR}/PLIST ${PKGDIR}/PLIST.oss
.endif

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GNURADIO_RUNTIME=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_ANALOG=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_AUDIO=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_BLOCKS=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_CTRLPORT=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FFT=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FILTER=ON

REPLACE_PYTHON+=	gnuradio-runtime/apps/evaluation_random_numbers.py
REPLACE_PYTHON+=	gnuradio-runtime/lib/math/gen_sine_table.py
REPLACE_PYTHON+=	gnuradio-runtime/python/gnuradio/*.py
REPLACE_PYTHON+=	gnuradio-runtime/python/gnuradio/gr/*.py
REPLACE_PYTHON+=	gnuradio-runtime/python/gnuradio/ctrlport/*.py
REPLACE_PYTHON+=	gnuradio-runtime/python/pmt/*.py
REPLACE_PYTHON+=	gr-analog/python/analog/*.py
REPLACE_PYTHON+=	gr-blocks/python/blocks/*.py
REPLACE_PYTHON+=	gr-fft/python/fft/*.py
REPLACE_PYTHON+=	gr-filter/python/filter/*.py

.include "../../mk/bsd.pkg.mk"
