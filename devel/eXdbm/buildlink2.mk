# $NetBSD: buildlink2.mk,v 1.1 2003/05/02 22:41:20 wiz Exp $
#
# This Makefile fragment is included by packages that use eXdbm.
#

.if !defined(EXDBM_BUILDLINK2_MK)
EXDBM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			eXdbm
BUILDLINK_DEPENDS.eXdbm?=		eXdbm>=1.0b1
BUILDLINK_PKGSRCDIR.eXdbm?=		../../devel/eXdbm

EVAL_PREFIX+=		BUILDLINK_PREFIX.eXdbm=eXdbm
BUILDLINK_PREFIX.eXdbm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.eXdbm+=		include/eXdbmErrors.h
BUILDLINK_FILES.eXdbm+=		include/eXdbmTypes.h
BUILDLINK_FILES.eXdbm+=		include/eXdbm.h
BUILDLINK_FILES.eXdbm+=		lib/libeXdbm.*

BUILDLINK_TARGETS+=	eXdbm-buildlink

eXdbm-buildlink: _BUILDLINK_USE

.endif	# EXDBM_BUILDLINK2_MK
