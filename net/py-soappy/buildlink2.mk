# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/10/01 17:21:39 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pysoappy
BUILDLINK_DEPENDS.pytk?=	${PYPKGPREFIX}-SOAPpy-*
BUILDLINK_PKGSRCDIR.pytk?=	../../net/py-soappy
