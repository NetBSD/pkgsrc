# $NetBSD: buildlink2.mk,v 1.3 2002/11/01 00:31:18 wiz Exp $

.if !defined(GDBM_BUILDLINK2_MK)
GDBM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gdbm
BUILDLINK_DEPENDS.gdbm?=	gdbm>=1.8.3
BUILDLINK_PKGSRCDIR.gdbm?=	../../databases/gdbm

EVAL_PREFIX+=	BUILDLINK_PREFIX.gdbm=gdbm
BUILDLINK_PREFIX.gdbm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gdbm=	include/gdbm.h
BUILDLINK_FILES.gdbm+=	lib/libgdbm.*

BUILDLINK_TARGETS+=	gdbm-buildlink

gdbm-buildlink: _BUILDLINK_USE

.endif	# GDBM_BUILDLINK2_MK
