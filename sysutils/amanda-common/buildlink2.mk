# $NetBSD: buildlink2.mk,v 1.2 2002/10/25 18:59:42 wiz Exp $
#

.if !defined(AMANDA_COMMON_BUILDLINK2_MK)
AMANDA_COMMON_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			amanda-common
BUILDLINK_DEPENDS.amanda-common?=	amanda-common>=2.4.2p2
BUILDLINK_PKGSRCDIR.amanda-common?=	../../sysutils/amanda-common

EVAL_PREFIX+=	BUILDLINK_PREFIX.amanda-common=amanda-common
BUILDLINK_PREFIX.amanda-common_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.amanda-common+=	lib/libamanda-2.4.2p2.*
BUILDLINK_FILES.amanda-common+=	lib/libamanda.*
BUILDLINK_FILES.amanda-common+=	lib/libamtape-2.4.2p2.*
BUILDLINK_FILES.amanda-common+=	lib/libamtape.*

BUILDLINK_TARGETS+=	amanda-common-buildlink

amanda-common-buildlink: _BUILDLINK_USE

.endif	# AMANDA_COMMON_BUILDLINK2_MK
