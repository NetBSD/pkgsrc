# $NetBSD: buildlink2.mk,v 1.6 2003/12/24 11:42:02 recht Exp $

.if !defined(SOAPPY_BUILDLINK2_MK)
SOAPPY_BUILDLINK2_MK=	# defined

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth
.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			SOAPpy
BUILDLINK_DEPENDS.SOAPpy?=		${PYPKGPREFIX}-SOAPpy>=0.11.1
BUILDLINK_PKGSRCDIR.SOAPpy?=		../../net/py-soappy

.include "../../textproc/pyxml/buildlink2.mk"

.endif	# SOAPPY_BUILDLINK2_MK
