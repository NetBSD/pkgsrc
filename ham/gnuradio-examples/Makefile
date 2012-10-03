# $NetBSD: Makefile,v 1.32 2012/10/03 13:01:44 asau Exp $

PKGNAME=	gnuradio-examples-${VERSION}
PKGREVISION=	14
COMMENT=	GUI framework for GNU Radio based on wxPython
COMMENT=	Examples for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-gnuradio-examples
CONFIGURE_ARGS+=--with-gnuradio-core --with-omnithread --with-gruel

EXAMPLE_DIR=	${LOCALBASE}/share/examples/gnuradio/python

PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/apps/hf_explorer/hfx2.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/apps/hf_radio/radio.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/apps/hf_radio/ui.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/audio_copy.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/audio_fft.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/audio_play.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/audio_to_file.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/dial_tone.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/mono_tone.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/multi_tone.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/spectrum_inversion.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/test_resampler.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/benchmark_rx.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/benchmark_tx.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/gen_whitener.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/pick_bitrate.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/receive_path.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/rx_voice.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/transmit_path.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/tunnel.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/tx_voice.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital_voice/encdec.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/multi-antenna/multi_fft.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/multi-antenna/multi_file.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/multi-antenna/multi_scope.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/multi_usrp/multi_usrp_oscope.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/multi_usrp/multi_usrp_rx_cfile.py

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
