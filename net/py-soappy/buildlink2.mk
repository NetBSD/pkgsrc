# $NetBSD: buildlink2.mk,v 1.2 2002/10/24 13:05:34 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pysoappy
BUILDLINK_DEPENDS.pysoappy?=	${PYPKGPREFIX}-SOAPpy-*
BUILDLINK_PKGSRCDIR.pysoappy?=	../../net/py-soappy
