# $NetBSD: Makefile,v 1.45 2014/05/05 00:48:01 ryoon Exp $

PKGNAME=	gnuradio-examples-${VERSION}
PKGREVISION=	26
COMMENT=	GUI framework for GNU Radio based on wxPython
COMMENT=	Examples for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gnuradio-examples
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

EXAMPLE_DIR=	${LOCALBASE}/share/examples/gnuradio/python

REPLACE_PYTHON+=	gnuradio-examples/python/apps/hf_explorer/hfx2.py
REPLACE_PYTHON+=	gnuradio-examples/python/apps/hf_radio/radio.py
REPLACE_PYTHON+=	gnuradio-examples/python/apps/hf_radio/ui.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/audio_copy.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/audio_fft.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/audio_play.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/audio_to_file.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/dial_tone.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/mono_tone.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/multi_tone.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/spectrum_inversion.py
REPLACE_PYTHON+=	gnuradio-examples/python/audio/test_resampler.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/benchmark_rx.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/benchmark_tx.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/gen_whitener.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/pick_bitrate.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/receive_path.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/rx_voice.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/transmit_path.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/tunnel.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital/tx_voice.py
REPLACE_PYTHON+=	gnuradio-examples/python/digital_voice/encdec.py
REPLACE_PYTHON+=	gnuradio-examples/python/multi-antenna/multi_fft.py
REPLACE_PYTHON+=	gnuradio-examples/python/multi-antenna/multi_file.py
REPLACE_PYTHON+=	gnuradio-examples/python/multi-antenna/multi_scope.py
REPLACE_PYTHON+=	gnuradio-examples/python/multi_usrp/multi_usrp_oscope.py
REPLACE_PYTHON+=	gnuradio-examples/python/multi_usrp/multi_usrp_rx_cfile.py

do-install:
	set -e;								\
	cd ${WRKSRC}/gnuradio-examples/python;				\
	for d in `find * -type d`;					\
	do								\
		${INSTALL_SCRIPT_DIR} ${DESTDIR}${EXAMPLE_DIR}/"$$d";	\
	done;								\
	for f in `find . \! -name "Makefile*" -type f`;			\
	do								\
		${INSTALL_SCRIPT} "$$f" ${DESTDIR}${EXAMPLE_DIR}/"$$f";	\
	done

.include "../../ham/gnuradio-wxgui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
