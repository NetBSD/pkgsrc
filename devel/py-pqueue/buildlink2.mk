# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:39 jlam Exp $

.if !defined(PY_PQUEUE_BUILDLINK2_MK)
PY_PQUEUE_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pypqueue
BUILDLINK_PKGBASE.pypqueue?=		${PYPKGPREFIX}-pqueue
BUILDLINK_DEPENDS.pypqueue?=		${PYPKGPREFIX}-pqueue-[0-9]*
BUILDLINK_PKGSRCDIR.pypqueue?=		../../devel/py-pqueue

.endif	# PY_PQUEUE_BUILDLINK2_MK
