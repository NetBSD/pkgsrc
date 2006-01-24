# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:17 wiz Exp $

DISTNAME=	gnuradio-examples-0.5
PKGREVISION=	1
COMMENT=	GUI framework for GNU Radio based on wxPython
COMMENT=	Examples for GNU Radio

PYTHON_PATCH_SCRIPTS+=	python/audio/audio_copy.py
PYTHON_PATCH_SCRIPTS+=	python/audio/audio_play.py
PYTHON_PATCH_SCRIPTS+=	python/audio/audio_to_file.py
PYTHON_PATCH_SCRIPTS+=	python/audio/dial_tone.py
PYTHON_PATCH_SCRIPTS+=	python/audio/mono_tone.py
PYTHON_PATCH_SCRIPTS+=	python/audio/multi_tone.py
PYTHON_PATCH_SCRIPTS+=	python/audio/spectrum_inversion.py
PYTHON_PATCH_SCRIPTS+=	python/audio/test_resampler.py
PYTHON_PATCH_SCRIPTS+=	python/digital_voice/encdec.py
PYTHON_PATCH_SCRIPTS+=  python/gmsk2/benchmark_gmsk_rx.py
PYTHON_PATCH_SCRIPTS+=  python/gmsk2/benchmark_gmsk_tx.py
PYTHON_PATCH_SCRIPTS+=  python/gmsk2/gen_whitener.py
PYTHON_PATCH_SCRIPTS+=  python/gmsk2/gmsk_test.py
PYTHON_PATCH_SCRIPTS+=  python/gmsk2/pick_bitrate.py
PYTHON_PATCH_SCRIPTS+=  python/gmsk2/receive_path.py
PYTHON_PATCH_SCRIPTS+=  python/gmsk2/transmit_path.py
PYTHON_PATCH_SCRIPTS+=  python/gmsk2/tunnel_ip_null_mac.py
PYTHON_PATCH_SCRIPTS+=	python/mc4020/fm_demod.py
PYTHON_PATCH_SCRIPTS+=	python/mc4020/mc4020_fft.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/am_rcv.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/ayfabtu.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/benchmark_usb.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/fm_tx4.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/fsk_loopback.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/fsk_rx.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/fsk_tx.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/max_power.py
PYTHON_PATCH_SCRIPTS+=  python/usrp/test_counting.py
PYTHON_PATCH_SCRIPTS+=  python/usrp/test_dft_analysis.py
PYTHON_PATCH_SCRIPTS+=  python/usrp/test_dft_synth.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/test_digital_loopback_counting.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/test_digital_loopback_lfsr.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/tvrx_am_rcv_gui.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/tvrx_tv_rcv.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/tweak_adc_offset.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_fft.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_fft_old.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_nbfm_ptt.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_nbfm_rcv.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_oscope.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_rx_cfile.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_rx_file.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_siggen.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_wfm_rcv.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_wfm_rcv_nogui.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_wfm_rcv_pll.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/wfm_rcv_file.py

EXAMPLE_DIR=	${LOCALBASE}/share/examples/gnuradio/python

do-install:
	for file in audio gmsk2 digital_voice  mc4020 usrp;		\
	do								\
		${INSTALL_SCRIPT_DIR} ${EXAMPLE_DIR}/$${file};		\
		${INSTALL_SCRIPT} ${WRKSRC}/python/$${file}/*\.py	\
		  ${EXAMPLE_DIR}/$${file};				\
	done

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/gnuradio-wxgui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
