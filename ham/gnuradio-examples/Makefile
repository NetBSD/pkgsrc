# $NetBSD: Makefile,v 1.15 2010/06/13 22:44:47 wiz Exp $

PKGNAME=	gnuradio-examples-${VERSION}
PKGREVISION=	3
COMMENT=	GUI framework for GNU Radio based on wxPython
COMMENT=	Examples for GNU Radio

PKG_DESTDIR_SUPPORT=	user-destdir

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
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/dial_squelch.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/dial_tone.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/dialtone_v.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/mono_tone.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/multi_tone.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/spectrum_inversion.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/audio/test_resampler.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/fsm_utils.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_sccc_hard.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_sccc_soft.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_sccc_turbo.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_tcm.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_tcm1.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_tcm2.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_tcm_combined.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_tcm_parallel.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_turbo_equalization.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_turbo_equalization1.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_turbo_equalization2.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_viterbi_equalization.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/channel-coding/test_viterbi_equalization1.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/benchmark_rx.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/benchmark_tx.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/digital/fusb_options.py
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
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/networking/measurement_slave.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/am_rcv.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/ayfabtu.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/ayfabtu.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/benchmark_usb.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/dsb_tx.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/flexrf_debug.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/flexrf_siggen.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/fm_tx4.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/fm_tx_2_daughterboards.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/max_power.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/siggen_min2.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/test_counting.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/test_dft_analysis.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/test_dft_synth.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/test_digital_loopback_counting.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/test_digital_loopback_lfsr.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/tvrx_am_rcv_gui.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_fft.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_fft_old.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_nbfm_ptt.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_nbfm_rcv.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_oscope.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_rx_cfile.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_rx_nogui.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_siggen.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_tv_rcv.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_tv_rcv_nogui.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_wfm_rcv.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_wfm_rcv2_nogui.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_wfm_rcv_nogui.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_wfm_rcv_pll.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/usrp_wxapt_rcv.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-examples/python/usrp/wfm_rcv_file.py

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
