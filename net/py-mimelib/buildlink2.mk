# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:42 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pymimelib
BUILDLINK_PKGBASE.pymimelib?=	${PYPKGPREFIX}-mimelib
BUILDLINK_DEPENDS.pymimelib?=	${PYPKGPREFIX}-mimelib-[0-9]*
BUILDLINK_PKGSRCDIR.pymimelib?=	../../net/py-mimelib
