# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/06 11:06:01 rh Exp $
#
# This Makefile fragment is included by packages that use xine-lib.
#

.if !defined(XINE_LIB_BUILDLINK2_MK)
XINE_LIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xine-lib
BUILDLINK_DEPENDS.xine-lib?=		xine-lib>=1.0rc9
BUILDLINK_PKGSRCDIR.xine-lib?=		../../graphics/xine-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.xine-lib=xine-lib
BUILDLINK_PREFIX.xine-lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xine-lib+=	include/xine.h
BUILDLINK_FILES.xine-lib+=	include/xine/*.h
BUILDLINK_FILES.xine-lib+=	lib/libxine.*
BUILDLINK_FILES.xine-lib+=	lib/pkgconfig/libxine.pc
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/post/xineplug_post_goom.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/post/xineplug_post_invert.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/post/xineplug_post_mosaico.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/post/xineplug_post_switch.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/post/xineplug_post_visualizations.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_ao_out_esd.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_ao_out_sun.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_a52.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_adpcm.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_cinepak.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_cyuv.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_dts.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_faad.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_ff.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_fli.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_gsm610.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_idcinvideo.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_interplayaudio.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_interplayvideo.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_logpcm.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_lpcm.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_mad.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_mpeg2.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_msrle.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_msvc.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_nsf.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_qt.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_qtrle.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_qtrpza.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_qtsmc.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_real.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_real_audio.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_rgb.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_roqaudio.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_roqvideo.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_spu.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_spucc.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_sputext.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_svq1.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_vorbis.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_w32dll.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_wc3video.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_yuv.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_decode_yuv_frames.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_asf.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_audio.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_avi.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_fli.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_games.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_mng.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_mpeg.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_mpeg_block.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_mpeg_elem.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_mpeg_ts.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_ogg.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_pva.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_qt.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_rawdv.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_real.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_sputext.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_yuv4mpeg2.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_dmx_yuv_frames.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_flac.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_cdda.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_dvb.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_dvd.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_file.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_gnome_vfs.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_http.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_mms.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_net.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_pnm.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_rtp.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_rtsp.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_stdin_fifo.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_inp_vcd.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_vo_out_aa.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_vo_out_none.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_vo_out_sdl.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_vo_out_syncfb.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_vo_out_xshm.*
BUILDLINK_FILES.xine-lib+=	lib/xine/plugins/1.0.0/xineplug_vo_out_xv.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/flac/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"

BUILDLINK_TARGETS+=	xine-lib-buildlink

xine-lib-buildlink: _BUILDLINK_USE

.endif	# XINE_LIB_BUILDLINK2_MK
