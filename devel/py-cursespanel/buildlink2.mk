# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:38 jlam Exp $

.if !defined(PYCURSESPANEL_BUILDLINK2_MK)
PYCURSESPANEL_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pycursespanel
BUILDLINK_PKGBASE.pycursespanel?=	${PYPKGPREFIX}-cursespanel
BUILDLINK_DEPENDS.pycursespanel?=	${PYPKGPREFIX}-cursespanel-[0-9]*
BUILDLINK_PKGSRCDIR.pycursespanel?=	../../devel/py-cursespanel

.include "../../devel/py-curses/buildlink2.mk"

.endif	# PYCURSESPANEL_BUILDLINK2_MK
