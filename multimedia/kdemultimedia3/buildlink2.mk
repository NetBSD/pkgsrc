# $NetBSD: buildlink2.mk,v 1.4 2004/04/05 18:41:14 wiz Exp $
#
# This Makefile fragment is included by packages that use kdemultimedia.
#
# This file was created automatically using createbuildlink-3.0.
#

.if !defined(KDEMULTIMEDIA_BUILDLINK2_MK)
KDEMULTIMEDIA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdemultimedia
BUILDLINK_DEPENDS.kdemultimedia?=		kdemultimedia>=3.2.1nb3
BUILDLINK_PKGSRCDIR.kdemultimedia?=		../../multimedia/kdemultimedia3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdemultimedia=kdemultimedia
BUILDLINK_PREFIX.kdemultimedia_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdemultimedia+=	include/arts/*
BUILDLINK_FILES.kdemultimedia+=	include/cmodule.h
BUILDLINK_FILES.kdemultimedia+=	include/effectview.h
BUILDLINK_FILES.kdemultimedia+=	include/equalizerview.h
BUILDLINK_FILES.kdemultimedia+=	include/ksaver.h
BUILDLINK_FILES.kdemultimedia+=	include/libkcddb/*
BUILDLINK_FILES.kdemultimedia+=	include/libwm/*
BUILDLINK_FILES.kdemultimedia+=	include/mimetypetree.h
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/decoder/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/frame/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/input/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/mpegutil/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/oggvorbis/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/output/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/splay/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/abstract/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/dynBuffer.h
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/file/fileAccess.h
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/mmx/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/render/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/syncClock.h
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/timeStamp.h
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/timeStampArray.h
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/timeWrapper.h
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/yaf/yafcore/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib/util/yaf/yafxplayer/*
BUILDLINK_FILES.kdemultimedia+=	include/mpeglib_artsplug/*
BUILDLINK_FILES.kdemultimedia+=	include/noatun/*
BUILDLINK_FILES.kdemultimedia+=	include/plugin_deps.h
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kcm_cddb.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kcm_kmix.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kcm_krec.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kcm_krec_files.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kfile_au.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kfile_avi.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kfile_flac.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kfile_m3u.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kfile_mp3.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kfile_ogg.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kfile_wav.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kmix.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kmix_panelapplet.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/kmixctrl.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/krec.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/libkaboodlepart.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/libkmidpart.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/libkrecexport_ogg.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/libkrecexport_wave.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_dcopiface.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_excellent.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_htmlexport.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_infrared.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_kaiman.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_keyz.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_kjofol.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_marquis.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_metatag.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_monoscope.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_net.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_splitplaylist.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_systray.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_ui.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_voiceprint.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatun_winskin.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/noatunsimple.*
BUILDLINK_FILES.kdemultimedia+=	lib/kde3/videothumbnail.*
BUILDLINK_FILES.kdemultimedia+=	lib/libarts_mpeglib-0.3.0.*
BUILDLINK_FILES.kdemultimedia+=	lib/libarts_mpeglib.*
BUILDLINK_FILES.kdemultimedia+=	lib/libarts_splay.*
BUILDLINK_FILES.kdemultimedia+=	lib/libarts_xine.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsbuilder.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartscontrolapplet.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartscontrolsupport.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartseffects.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsgui.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsgui_idl.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsgui_kde.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsmidi.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsmidi_idl.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsmodules.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsmodulescommon.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsmoduleseffects.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsmodulesmixers.*
BUILDLINK_FILES.kdemultimedia+=	lib/libartsmodulessynth.*
BUILDLINK_FILES.kdemultimedia+=	lib/libaudiofilearts.*
BUILDLINK_FILES.kdemultimedia+=	lib/libkcddb.*
BUILDLINK_FILES.kdemultimedia+=	lib/libkdeinit_kmix.*
BUILDLINK_FILES.kdemultimedia+=	lib/libkdeinit_kmixctrl.*
BUILDLINK_FILES.kdemultimedia+=	lib/libkdeinit_krec.*
BUILDLINK_FILES.kdemultimedia+=	lib/libkdeinit_noatun.*
BUILDLINK_FILES.kdemultimedia+=	lib/libmpeg-0.3.0.*
BUILDLINK_FILES.kdemultimedia+=	lib/libmpeg.*
BUILDLINK_FILES.kdemultimedia+=	lib/libnoatun.*
BUILDLINK_FILES.kdemultimedia+=	lib/libnoatunarts.*
BUILDLINK_FILES.kdemultimedia+=	lib/libnoatuncontrols.*
BUILDLINK_FILES.kdemultimedia+=	lib/libnoatuntags.*
BUILDLINK_FILES.kdemultimedia+=	lib/libwinskinvis.*
BUILDLINK_FILES.kdemultimedia+=	lib/libworkman.*
BUILDLINK_FILES.kdemultimedia+=	lib/libworkmanaudio.*
BUILDLINK_FILES.kdemultimedia+=	lib/libyafcore.*
BUILDLINK_FILES.kdemultimedia+=	lib/libyafxplayer.*

.include "../../audio/arts/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../multimedia/xine-lib/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdemultimedia-buildlink

kdemultimedia-buildlink: _BUILDLINK_USE

.endif	# KDEMULTIMEDIA_BUILDLINK2_MK
