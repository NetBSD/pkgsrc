# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/08/11 14:56:54 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pymimelib
BUILDLINK_DEPENDS.pymimelib?=	${PYPKGPREFIX}-mimelib-[0-9]*
BUILDLINK_PKGSRCDIR.pymimelib?=	../../net/py-mimelib
