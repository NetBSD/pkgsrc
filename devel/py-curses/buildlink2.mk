# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:38 jlam Exp $

.if !defined(PYCURSES_BUILDLINK2_MK)
PYCURSES_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pycurses
BUILDLINK_PKGBASE.pycurses?=		${PYPKGPREFIX}-curses
BUILDLINK_DEPENDS.pycurses?=		${PYPKGPREFIX}-curses-[0-9]*
BUILDLINK_PKGSRCDIR.pycurses?=		../../devel/py-curses

.endif	# PYCURSES_BUILDLINK2_MK
