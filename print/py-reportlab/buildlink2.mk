# $NetBSD: buildlink2.mk,v 1.2 2002/12/10 15:11:02 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyreportlab
BUILDLINK_DEPENDS.pyreportlab?= ${PYPKGPREFIX}-reportlab-[0-9]*
BUILDLINK_PKGSRCDIR.pyreportlab=../../print/py-reportlab
