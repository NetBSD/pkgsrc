# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:43 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyreportlab
BUILDLINK_PKGBASE.pyreportlab?= ${PYPKGPREFIX}-reportlab
BUILDLINK_DEPENDS.pyreportlab?= ${PYPKGPREFIX}-reportlab-[0-9]*
BUILDLINK_PKGSRCDIR.pyreportlab=../../print/py-reportlab
