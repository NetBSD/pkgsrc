# $NetBSD: buildlink.mk,v 1.2 2002/01/15 18:38:46 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pynumeric?= ${PYPKGPREFIX}-Numeric-*
DEPENDS+= ${BUILDLINK_DEPENDS.pynumeric}:../math/py-Numeric
