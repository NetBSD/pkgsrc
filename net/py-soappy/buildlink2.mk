# $NetBSD: buildlink2.mk,v 1.3 2003/03/19 11:51:09 drochner Exp $

.if !defined(SOAPPY_BUILDLINK2_MK)
SOAPPY_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			SOAPpy
BUILDLINK_DEPENDS.SOAPpy?=		${PYPKGPREFIX}-SOAPpy>=0.9.8
BUILDLINK_PKGSRCDIR.SOAPpy?=		../../net/py-soappy

.include "../../textproc/pyxml/buildlink2.mk"

.endif	# SOAPPY_BUILDLINK2_MK
