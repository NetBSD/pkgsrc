# $NetBSD: buildlink2.mk,v 1.9 2004/03/29 05:05:42 jlam Exp $

.if !defined(SOAPPY_BUILDLINK2_MK)
SOAPPY_BUILDLINK2_MK=	# defined

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth
.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			SOAPpy
BUILDLINK_PKGBASE.SOAPpy?=		${PYPKGPREFIX}-SOAPpy
BUILDLINK_DEPENDS.SOAPpy?=		${PYPKGPREFIX}-SOAPpy>=0.11.1
BUILDLINK_RECOMMENDED.SOAPpy?=		${PYPKGPREFIX}-SOAPpy>=0.11.3nb1
BUILDLINK_PKGSRCDIR.SOAPpy?=		../../net/py-soappy

.include "../../textproc/py-xml/buildlink2.mk"

.endif	# SOAPPY_BUILDLINK2_MK
