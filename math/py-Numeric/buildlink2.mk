# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:08 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pynumeric
BUILDLINK_DEPENDS.pynumeric?=	${PYPKGPREFIX}-Numeric-*
BUILDLINK_PKGSRCDIR.pynumeric?=	../../math/py-Numeric
