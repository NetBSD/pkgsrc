# $NetBSD: buildlink.mk,v 1.1 2002/10/23 18:05:23 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pyreportlab?= ${PYPKGPREFIX}-reportlab-*
DEPENDS+= ${BUILDLINK_DEPENDS.pyreportlab}:../../print/py-reportlab
