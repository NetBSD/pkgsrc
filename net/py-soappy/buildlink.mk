# $NetBSD: buildlink.mk,v 1.1.1.1 2002/10/01 17:21:39 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pysoappy?= ${PYPKGPREFIX}-SOAPpy-*
DEPENDS+= ${BUILDLINK_DEPENDS.pysoappy}:../../net/py-soappy
