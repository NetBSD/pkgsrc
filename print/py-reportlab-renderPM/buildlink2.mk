# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:44 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyrlrenderpm
BUILDLINK_PKGBASE.pyrlrenderpm?= ${PYPKGPREFIX}-reportlab-renderPM
BUILDLINK_DEPENDS.pyrlrenderpm?= ${PYPKGPREFIX}-reportlab-renderPM-[0-9]*
BUILDLINK_PKGSRCDIR.pyrlrenderpm=../../print/py-reportlab-renderPM
