# $NetBSD: buildlink2.mk,v 1.2 2003/05/02 11:56:06 wiz Exp $
#
# This Makefile fragment is included by packages that use kdenetwork.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(KDENETWORK_BUILDLINK2_MK)
KDENETWORK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdenetwork
BUILDLINK_DEPENDS.kdenetwork?=		kdenetwork>=2.2.2nb5
BUILDLINK_PKGSRCDIR.kdenetwork?=		../../net/kdenetwork2

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdenetwork=kdenetwork
BUILDLINK_PREFIX.kdenetwork_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdenetwork+=	include/kmailIface.h
BUILDLINK_FILES.kdenetwork+=	include/mimelib/*
BUILDLINK_FILES.kdenetwork+=	lib/kde2/libkcm_ktalkd.*
BUILDLINK_FILES.kdenetwork+=	lib/kio_lan.*
BUILDLINK_FILES.kdenetwork+=	lib/ksirc.*
BUILDLINK_FILES.kdenetwork+=	lib/libkcm_lanbrowser.*
BUILDLINK_FILES.kdenetwork+=	lib/libkcm_newsticker.*
BUILDLINK_FILES.kdenetwork+=	lib/libkdenetwork.*
BUILDLINK_FILES.kdenetwork+=	lib/libkdictapplet.*
BUILDLINK_FILES.kdenetwork+=	lib/libknewstickerapplet.*
BUILDLINK_FILES.kdenetwork+=	lib/libkntsrcfilepropsdlg.*
BUILDLINK_FILES.kdenetwork+=	lib/libmimelib.*

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

BUILDLINK_TARGETS+=	kdenetwork-buildlink

kdenetwork-buildlink: _BUILDLINK_USE

.endif	# KDENETWORK_BUILDLINK2_MK
