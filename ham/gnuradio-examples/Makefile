# $NetBSD: Makefile,v 1.2 2005/10/11 12:02:14 wulf Exp $

DISTNAME=	gnuradio-examples-0.4
COMMENT=	GUI framework for GNU Radio based on wxPython
COMMENT=	Examples for GNU Radio

PYTHON_PATCH_SCRIPTS+=	python/audio/audio_copy.py
PYTHON_PATCH_SCRIPTS+=	python/audio/audio_play.py
PYTHON_PATCH_SCRIPTS+=	python/audio/audio_to_file.py
PYTHON_PATCH_SCRIPTS+=	python/audio/dial_tone.py
PYTHON_PATCH_SCRIPTS+=	python/audio/mono_tone.py
PYTHON_PATCH_SCRIPTS+=	python/audio/multi_tone.py
PYTHON_PATCH_SCRIPTS+=	python/audio/spectrum_inversion.py
PYTHON_PATCH_SCRIPTS+=	python/gmsk/ggmsk-test.py
PYTHON_PATCH_SCRIPTS+=	python/gmsk/gmsk-test.py
PYTHON_PATCH_SCRIPTS+=	python/gmsk/rx.py
PYTHON_PATCH_SCRIPTS+=	python/gmsk/tx.py
PYTHON_PATCH_SCRIPTS+=	python/mc4020/fm_demod.py
PYTHON_PATCH_SCRIPTS+=	python/mc4020/mc4020_fft.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/am_rcv.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/benchmark_usb.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/dbs_debug.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/dbs_fft.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/dbs_nbfm.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/dsb_tx.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/fm_tx4.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/fsk_loopback.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/fsk_rx.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/fsk_tx.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/max_power.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/nbfm_ptt_quick_and_dirty.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/nbfm_rcv.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/test_counting.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/test_digital_loopback_counting.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/test_digital_loopback_lfsr.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/tvrx_debug.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/tvrx_wfm_rcv_gui.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/tweak_adc_offset.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_fft.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_fft_simple.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_oscope.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_rx_cfile.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_rx_file.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/usrp_siggen.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/wfm_rcv.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/wfm_rcv_dual.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/wfm_rcv_file.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/wfm_rcv_gui.py
PYTHON_PATCH_SCRIPTS+=	python/usrp/wfm_rcv_many.py

EXAMPLE_DIR=	${LOCALBASE}/share/examples/gnuradio/python

do-install:
	for file in audio gmsk mc4020 usrp;				\
	do								\
		${INSTALL_SCRIPT_DIR} ${EXAMPLE_DIR}/$${file};		\
		${INSTALL_SCRIPT} ${WRKSRC}/python/$${file}/*\.py	\
		  ${EXAMPLE_DIR}/$${file};				\
	done

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/gnuradio-wxgui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
