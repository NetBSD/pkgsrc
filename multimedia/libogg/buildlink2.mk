# $NetBSD: buildlink2.mk,v 1.3 2004/04/24 23:18:10 wiz Exp $
#

.if !defined(LIBOGG_BUILDLINK2_MK)
LIBOGG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libogg
BUILDLINK_DEPENDS.libogg?=	libogg>=1.1
BUILDLINK_PKGSRCDIR.libogg?=	../../multimedia/libogg

EVAL_PREFIX+=	BUILDLINK_PREFIX.libogg=libogg
BUILDLINK_PREFIX.libogg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libogg=		include/ogg/config_types.h
BUILDLINK_FILES.libogg+=	include/ogg/ogg.h
BUILDLINK_FILES.libogg+=	include/ogg/os_types.h
BUILDLINK_FILES.libogg+=	lib/libogg.*

BUILDLINK_TARGETS+=		libogg-buildlink

libogg-buildlink: _BUILDLINK_USE

.endif	# LIBOGG_BUILDLINK2_MK
