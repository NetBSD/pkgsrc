# $NetBSD: buildlink.mk,v 1.1 2002/01/10 20:47:51 drochner Exp $

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-Numeric-*:../math/py-Numeric
