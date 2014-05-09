# $NetBSD: Makefile,v 1.40 2014/05/09 07:37:08 wiz Exp $

PKGNAME=	gnuradio-core-${VERSION}
PKGREVISION=	10
COMMENT=	Runtime system and DSP blocks for GNU Radio

LDFLAGS.DragonFly+=	-lboost_system
LDFLAGS.SunOS+=		-lboost_system

PYTHON_VERSIONS_INCOMPATIBLE=   33 34 # not yet ported as of 3.3.0
.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=	${EGDIR}/gnuradio-core.conf ${PKG_SYSCONFDIR}/gnuradio-core.conf
CONFIGURE_ARGS+=	--enable-gnuradio-core
CONFIGURE_ARGS+=	--enable-omnithread
CONFIGURE_ARGS+=	--enable-gruel

REPLACE_PYTHON+=	gnuradio-core/src/lib/swig/gen-swig-bug-fix
REPLACE_PYTHON+=	gnuradio-core/src/python/bin/microtune.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/general/gen_sine_table.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_gr_fir_XXX.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_all.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_gr_interp_fir_filter_XXX.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_gr_fir_filter_XXX.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_gr_rational_resampler_base_XXX.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_gr_fir_sysconfig.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_gr_fir_sysconfig_generic.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_gr_fir_util.py
REPLACE_PYTHON+=	gnuradio-core/src/lib/filter/generate_gr_freq_xlating_fir_filter_XXX.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/channel_model.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_receiver.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_sync_fixed.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_sync_ml.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_sync_pn.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/ofdm_sync_pnac.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/pfb_arb_resampler.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/pfb_channelizer.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/pfb_decimator.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/blks2impl/pfb_interpolator.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/benchmark_filters.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/pubsub.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_add_and_friends.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_correlate_access_code.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_add_v_and_friends.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_agc.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_cma_equalizer.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_complex_to_xxx.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_fft_filter.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_feval.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_constellation_decoder_cb.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_diff_encoder.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_diff_phasor_cc.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_frequency_modulator.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_filter_delay_fc.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_interp_fir_filter.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_fsk_stuff.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_goertzel.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_head.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_hilbert.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_iir.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_interleave.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_kludge_copy.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_message.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_kludged_imports.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_mute.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_nlog10.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_packed_to_unpacked.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_pipe_fittings.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_rational_resampler.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_sig_source.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_single_pole_iir.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_single_pole_iir_cc.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr/qa_unpack_k_bits.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gruimpl/gnuplot_freqz.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gruimpl/freqz.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gruimpl/lmx2306.py
REPLACE_PYTHON+=	gnuradio-core/src/python/gnuradio/gr_unittest.py
REPLACE_PYTHON+=	gnuradio-core/src/tests/test_buffers.py

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
