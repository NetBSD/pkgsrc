# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:35 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pynumeric
BUILDLINK_DEPENDS.pynumeric?=	${PYPKGPREFIX}-Numeric-*
BUILDLINK_PKGSRCDIR.pynumeric?=	../../math/py-Numeric
