# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:39 jlam Exp $

.if !defined(PY_KJB_BUILDLINK2_MK)
PY_KJB_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pykjb
BUILDLINK_PKGBASE.pykjb?=		${PYPKGPREFIX}-kjbuckets
BUILDLINK_DEPENDS.pykjb?=		${PYPKGPREFIX}-kjbuckets-[0-9]*
BUILDLINK_PKGSRCDIR.pykjb?=		../../devel/py-kjbuckets

.endif	# PY_KJB_BUILDLINK2_MK
