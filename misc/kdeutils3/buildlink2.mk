# $NetBSD: buildlink2.mk,v 1.9 2003/12/08 14:41:40 wiz Exp $
#
# This Makefile fragment is included by packages that use kdeutils.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(KDEUTILS_BUILDLINK2_MK)
KDEUTILS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdeutils
BUILDLINK_DEPENDS.kdeutils?=		kdeutils>=3.1.4nb1
BUILDLINK_PKGSRCDIR.kdeutils?=		../../misc/kdeutils3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdeutils=kdeutils
BUILDLINK_PREFIX.kdeutils_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdeutils+=	include/kmultiformlistbox.h
BUILDLINK_FILES.kdeutils+=	include/kmultiformlistboxentry.h
BUILDLINK_FILES.kdeutils+=	include/kmultiformlistboxfactory.h
BUILDLINK_FILES.kdeutils+=	include/kwidgetstreamer.h
BUILDLINK_FILES.kdeutils+=	lib/kcalc.*
BUILDLINK_FILES.kdeutils+=	lib/kde3/kcharselectapplet.*
BUILDLINK_FILES.kdeutils+=	lib/kde3/kcm_kdf.*
BUILDLINK_FILES.kdeutils+=	lib/kde3/kcm_laptop.*
BUILDLINK_FILES.kdeutils+=	lib/kde3/libkregexpeditorgui.*
BUILDLINK_FILES.kdeutils+=	lib/kedit.*
BUILDLINK_FILES.kdeutils+=	lib/klaptopdaemon.*
BUILDLINK_FILES.kdeutils+=	lib/libark.*
BUILDLINK_FILES.kdeutils+=	lib/libkcalc_main.*
BUILDLINK_FILES.kdeutils+=	lib/libkedit_main.*
BUILDLINK_FILES.kdeutils+=	lib/libklaptopdaemon_main.*

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdeutils-buildlink

kdeutils-buildlink: _BUILDLINK_USE

.endif	# KDEUTILS_BUILDLINK2_MK
