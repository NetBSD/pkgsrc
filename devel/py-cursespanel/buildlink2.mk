# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/06/04 19:32:13 drochner Exp $

.if !defined(PYCURSESPANEL_BUILDLINK2_MK)
PYCURSESPANEL_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pycursespanel
BUILDLINK_DEPENDS.pycursespanel?=	${PYPKGPREFIX}-cursespanel-[0-9]*
BUILDLINK_PKGSRCDIR.pycursespanel?=	../../devel/py-cursespanel

.include "../../devel/py-curses/buildlink2.mk"

.endif	# PYCURSESPANEL_BUILDLINK2_MK
