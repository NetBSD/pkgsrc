# $NetBSD: buildlink2.mk,v 1.1 2003/06/04 19:27:55 drochner Exp $

.if !defined(PYCURSES_BUILDLINK2_MK)
PYCURSES_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pycurses
BUILDLINK_DEPENDS.pycurses?=		${PYPKGPREFIX}-curses-[0-9]*
BUILDLINK_PKGSRCDIR.pycurses?=		../../devel/py-curses

.endif	# PYCURSES_BUILDLINK2_MK
