# $NetBSD: buildlink2.mk,v 1.2 2003/07/13 13:52:29 wiz Exp $
#
# This Makefile fragment is included by packages that use cassowary.
#

.if !defined(CASSOWARY_BUILDLINK2_MK)
CASSOWARY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			cassowary
BUILDLINK_DEPENDS.cassowary?=		cassowary>=0.60nb4
BUILDLINK_PKGSRCDIR.cassowary?=		../../math/cassowary

EVAL_PREFIX+=	BUILDLINK_PREFIX.cassowary=cassowary
BUILDLINK_PREFIX.cassowary_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cassowary+=	include/Cl.h
BUILDLINK_FILES.cassowary+=	include/ClC.h
BUILDLINK_FILES.cassowary+=	include/cassowary/*
BUILDLINK_FILES.cassowary+=	include/cassowary*.h
BUILDLINK_FILES.cassowary+=	include/cl-snarf.h
BUILDLINK_FILES.cassowary+=	lib/libcassowary.*

.include "../../devel/gtl/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"

BUILDLINK_TARGETS+=	cassowary-buildlink

cassowary-buildlink: _BUILDLINK_USE

.endif	# CASSOWARY_BUILDLINK2_MK
