# $NetBSD: buildlink2.mk,v 1.2 2003/05/02 11:56:26 wiz Exp $
#
# This Makefile fragment is included by packages that use medusa.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(MEDUSA_BUILDLINK2_MK)
MEDUSA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			medusa
BUILDLINK_DEPENDS.medusa?=		medusa>=0.5.1nb2
BUILDLINK_PKGSRCDIR.medusa?=		../../sysutils/medusa

EVAL_PREFIX+=	BUILDLINK_PREFIX.medusa=medusa
BUILDLINK_PREFIX.medusa_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.medusa+=	include/libmedusa/*
BUILDLINK_FILES.medusa+=	lib/libmedusa-index.*
BUILDLINK_FILES.medusa+=	lib/libmedusa.*
BUILDLINK_FILES.medusa+=	lib/vfs/modules/libvfs-search.*	# XXX ???

.include "../../sysutils/gnome-vfs/buildlink2.mk"

BUILDLINK_TARGETS+=	medusa-buildlink

medusa-buildlink: _BUILDLINK_USE

.endif	# MEDUSA_BUILDLINK2_MK
