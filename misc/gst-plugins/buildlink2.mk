# $NetBSD: buildlink2.mk,v 1.5 2003/12/08 14:41:40 wiz Exp $
#
# This Makefile fragment is included by packages that use gst-plugins.
#

.if !defined(GST_PLUGINS_BUILDLINK2_MK)
GST_PLUGINS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gst-plugins
BUILDLINK_DEPENDS.gst-plugins?=		gst-plugins>=0.6.1nb7
BUILDLINK_PKGSRCDIR.gst-plugins?=		../../misc/gst-plugins

EVAL_PREFIX+=	BUILDLINK_PREFIX.gst-plugins=gst-plugins
BUILDLINK_PREFIX.gst-plugins_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/audio/*.h
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/floatcast/*.h
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/gconf/*.h
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/idct/*.h
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/media-info/*.h
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/play/*.h
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/resample/*.h
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/riff/*.h
BUILDLINK_FILES.gst-plugins+=	include/gstreamer-0.6/gst/video/*.h
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgsta52dec.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstaasink.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstac3parse.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstadder.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstalaw.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstaudio.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstaudioscale.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstauparse.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstavidemux.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstavimux.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstcdparanoia.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstcdplayer.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstcdxaparse.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstchart.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstcolorspace.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstcutter.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstdeinterlace.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstdvdreadsrc.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgsteffectv.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstesdmon.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstesdsink.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstfestival.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstfilter.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstflac.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstflxdec.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstgnomevfssink.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstgnomevfssrc.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstgoom.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstgsm.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgsthttpsrc.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstidct.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstintfloat.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstjpeg.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstlame.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstlevel.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmad.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmedian.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmikmod.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmodplug.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmono2stereo.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmonoscope.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmp1videoparse.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmp3types.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpeg1encoder.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpeg1systemencode.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpeg1types.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpeg2enc.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpeg2subt.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpeg2types.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpegaudio.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpegaudioparse.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmpegstream.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstmulaw.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstoneton.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstopenquicktimedecoder.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstopenquicktimedemux.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstopenquicktimetypes.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstossaudio.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstpassthrough.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstplayondemand.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstqtdemux.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstresample.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstriff.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstrtjpeg.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstsdlvideosink.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstsid.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstsilence.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstsinesrc.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstsmooth.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstsmpte.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstspectrum.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstspeed.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgststereo.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgststereo2mono.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgststereosplit.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstswfdec.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstsynaesthesia.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstudp.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvbidec.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvideo.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvideocrop.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvideoscale.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvideosink.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvideotestsrc.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvolenv.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvolume.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvorbis.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstvumeter.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstwavenc.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstwavparse.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgstxvideosink.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libgsty4menc.*
BUILDLINK_FILES.gst-plugins+=	lib/gstreamer-0.6/libmixmatrix.*
BUILDLINK_FILES.gst-plugins+=	lib/libgstgconf-0.6.*
BUILDLINK_FILES.gst-plugins+=	lib/libgstmedia-info-0.6.*
BUILDLINK_FILES.gst-plugins+=	lib/libgstplay-0.6.*
BUILDLINK_FILES.gst-plugins+=	lib/pkgconfig/gstreamer-gconf-0.6.pc
BUILDLINK_FILES.gst-plugins+=	lib/pkgconfig/gstreamer-libs-0.6.pc
BUILDLINK_FILES.gst-plugins+=	lib/pkgconfig/gstreamer-play-0.6.pc

BUILDLINK_TARGETS+=	gst-plugins-buildlink

gst-plugins-buildlink: _BUILDLINK_USE

.endif	# GST_PLUGINS_BUILDLINK2_MK
