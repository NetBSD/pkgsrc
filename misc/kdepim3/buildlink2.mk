# $NetBSD: buildlink2.mk,v 1.8 2003/12/08 14:41:40 wiz Exp $
#
# This Makefile fragment is included by packages that use kdepim.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(KDEPIM_BUILDLINK2_MK)
KDEPIM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdepim
BUILDLINK_DEPENDS.kdepim?=		kdepim>=3.1.4nb1
BUILDLINK_PKGSRCDIR.kdepim?=		../../misc/kdepim3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdepim=kdepim
BUILDLINK_PREFIX.kdepim_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdepim+=	include/KNotesIface.h
BUILDLINK_FILES.kdepim+=	include/calendar/*
BUILDLINK_FILES.kdepim+=	include/kgantt/*
BUILDLINK_FILES.kdepim+=	include/korganizer/*
BUILDLINK_FILES.kdepim+=	include/kpilot/*
BUILDLINK_FILES.kdepim+=	lib/kde3/libabbrowserconduit.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libexpenseconduit.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkcm_alarmdaemonctrl.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libknotesconduit.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_datenums.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_holidays.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_projectview.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_webexport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libnullconduit.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libpopmailconduit.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libtodoconduit.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libvcalconduit.*
BUILDLINK_FILES.kdepim+=	lib/libkalarmd.*
BUILDLINK_FILES.kdepim+=	lib/libkcal.*
BUILDLINK_FILES.kdepim+=	lib/libkgantt.*
BUILDLINK_FILES.kdepim+=	lib/libkorganizer.*
BUILDLINK_FILES.kdepim+=	lib/libkpilot.*

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdepim-buildlink

kdepim-buildlink: _BUILDLINK_USE

.endif	# KDEPIM_BUILDLINK2_MK
