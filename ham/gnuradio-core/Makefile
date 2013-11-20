# $NetBSD: Makefile,v 1.37 2013/11/20 20:04:35 adam Exp $

PKGNAME=	gnuradio-core-${VERSION}
PKGREVISION=	10
COMMENT=	Runtime system and DSP blocks for GNU Radio

LDFLAGS.DragonFly+=	-lboost_system
LDFLAGS.SunOS+=		-lboost_system

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=	${EGDIR}/gnuradio-core.conf ${PKG_SYSCONFDIR}/gnuradio-core.conf
CONFIGURE_ARGS+=	--enable-gnuradio-core
CONFIGURE_ARGS+=	--enable-omnithread
CONFIGURE_ARGS+=	--enable-gruel

PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/swig/gen-swig-bug-fix
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/bin/microtune.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/general/gen_sine_table.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_gr_fir_XXX.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_all.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_gr_interp_fir_filter_XXX.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_gr_fir_filter_XXX.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_gr_rational_resampler_base_XXX.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_gr_fir_sysconfig.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_gr_fir_sysconfig_generic.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_gr_fir_util.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/lib/filter/generate_gr_freq_xlating_fir_filter_XXX.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/channel_model.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_receiver.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_sync_fixed.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_sync_ml.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_sync_pn.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_sync_pnac.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/pfb_arb_resampler.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/pfb_channelizer.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/pfb_decimator.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/blks2impl/pfb_interpolator.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/benchmark_filters.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/pubsub.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_add_and_friends.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_correlate_access_code.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_add_v_and_friends.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_agc.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_cma_equalizer.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_complex_to_xxx.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_fft_filter.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_feval.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_constellation_decoder_cb.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_diff_encoder.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_diff_phasor_cc.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_frequency_modulator.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_filter_delay_fc.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_interp_fir_filter.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_fsk_stuff.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_goertzel.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_head.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_hilbert.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_iir.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_interleave.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_kludge_copy.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_message.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_kludged_imports.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_mute.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_nlog10.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_packed_to_unpacked.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_pipe_fittings.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_rational_resampler.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_sig_source.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_single_pole_iir.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_single_pole_iir_cc.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr/qa_unpack_k_bits.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gruimpl/gnuplot_freqz.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gruimpl/freqz.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gruimpl/lmx2306.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/python/gnuradio/gr_unittest.py
PYTHON_PATCH_SCRIPTS+=	gnuradio-core/src/tests/test_buffers.py

.include "../../devel/swig/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
BUILDLINK_DEPMETHOD.guile=	build
.include "../../lang/guile/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
