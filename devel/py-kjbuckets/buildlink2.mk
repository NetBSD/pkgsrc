# $NetBSD: buildlink2.mk,v 1.1 2003/07/25 16:01:15 drochner Exp $

.if !defined(PY_KJB_BUILDLINK2_MK)
PY_KJB_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pykjb
BUILDLINK_DEPENDS.pykjb?=		${PYPKGPREFIX}-kjbuckets-[0-9]*
BUILDLINK_PKGSRCDIR.pykjb?=		../../devel/py-kjbuckets

.endif	# PY_KJB_BUILDLINK2_MK
