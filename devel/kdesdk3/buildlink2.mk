# $NetBSD: buildlink2.mk,v 1.10 2004/02/05 08:27:59 markd Exp $
#
# This Makefile fragment is included by packages that use kdesdk.
#
# This file was created automatically using createbuildlink-3.0.
#

.if !defined(KDESDK_BUILDLINK2_MK)
KDESDK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdesdk
BUILDLINK_DEPENDS.kdesdk?=		kdesdk>=3.2.0
BUILDLINK_PKGSRCDIR.kdesdk?=		../../devel/kdesdk3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdesdk=kdesdk
BUILDLINK_PREFIX.kdesdk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdesdk+=	include/cvsjob_stub.h
BUILDLINK_FILES.kdesdk+=	include/cvsservice_stub.h
BUILDLINK_FILES.kdesdk+=	include/kbabel/*
BUILDLINK_FILES.kdesdk+=	include/kprofilemethod.h
BUILDLINK_FILES.kdesdk+=	include/kspy.h
BUILDLINK_FILES.kdesdk+=	include/repository_stub.h
BUILDLINK_FILES.kdesdk+=	lib/kde3/kabcformat_kdeaccounts.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_accelstool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_argstool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_contexttool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_equationstool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_gettextexport.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_gettextimport.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_lengthtool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_linguistexport.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_linguistimport.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_nottranslatedtool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_pluraltool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_punctuationtool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_setfuzzytool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_whitespacetool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabel_xmltool.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabeldict_poauxiliary.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabeldict_pocompendium.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kbabeldict_tmxcompendium.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kfile_cpp.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kfile_diff.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kfile_po.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/kfile_ts.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/libcervisiapart.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/libkomparenavtreepart.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/libkomparepart.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/libkuiviewerpart.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/plugins/styles/scheck.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/pothumbnail.*
BUILDLINK_FILES.kdesdk+=	lib/kde3/quithumbnail.*
BUILDLINK_FILES.kdesdk+=	lib/libcvsservice.*
BUILDLINK_FILES.kdesdk+=	lib/libkbabelcommon.*
BUILDLINK_FILES.kdesdk+=	lib/libkbabeldictplugin.*
BUILDLINK_FILES.kdesdk+=	lib/libkompareinterface.*
BUILDLINK_FILES.kdesdk+=	lib/libkspy.*

.include "../../databases/db/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdesdk-buildlink

kdesdk-buildlink: _BUILDLINK_USE

.endif	# KDESDK_BUILDLINK2_MK
