# $NetBSD: buildlink2.mk,v 1.1 2002/10/24 13:51:08 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyreportlab
BUILDLINK_DEPENDS.pyreportlab?= ${PYPKGPREFIX}-reportlab-*
BUILDLINK_PKGSRCDIR.pyreportlab=../../print/py-reportlab
