# $NetBSD: buildlink2.mk,v 1.2 2003/05/02 11:54:32 wiz Exp $
#
# This Makefile fragment is included by packages that use kdesdk.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(KDESDK_BUILDLINK2_MK)
KDESDK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdesdk
BUILDLINK_DEPENDS.kdesdk?=		kdesdk>=2.2.2nb2
BUILDLINK_PKGSRCDIR.kdesdk?=		../../devel/kdesdk2

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdesdk=kdesdk
BUILDLINK_PREFIX.kdesdk_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdesdk+=	include/kbabel/*
BUILDLINK_FILES.kdesdk+=	include/kspy.h
BUILDLINK_FILES.kdesdk+=	lib/kde2/libdbsearchengine.*
BUILDLINK_FILES.kdesdk+=	lib/kde2/libpoauxiliary.*
BUILDLINK_FILES.kdesdk+=	lib/kde2/libpocompendium.*
BUILDLINK_FILES.kdesdk+=	lib/kde2/pothumbnail.*
BUILDLINK_FILES.kdesdk+=	lib/libkbabel.*
BUILDLINK_FILES.kdesdk+=	lib/libkbabelcommon.*
BUILDLINK_FILES.kdesdk+=	lib/libkbabeldict.*
BUILDLINK_FILES.kdesdk+=	lib/libkbabeldictplugin.*
BUILDLINK_FILES.kdesdk+=	lib/libkspy.*
BUILDLINK_FILES.kdesdk+=	lib/libkstartperf.*

.include "../../databases/db/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

BUILDLINK_TARGETS+=	kdesdk-buildlink

kdesdk-buildlink: _BUILDLINK_USE

.endif	# KDESDK_BUILDLINK2_MK
