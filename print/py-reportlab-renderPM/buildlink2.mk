# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/28 15:08:50 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyrlrenderpm
BUILDLINK_DEPENDS.pyrlrenderpm?= ${PYPKGPREFIX}-reportlab-renderPM-*
BUILDLINK_PKGSRCDIR.pyrlrenderpm=../../print/py-reportlab-renderPM
