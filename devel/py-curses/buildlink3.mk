# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:27 joerg Exp $

BUILDLINK_TREE+=	pycurses

.if !defined(PY_CURSES_BUILDLINK3_MK)
PY_CURSES_BUILDLINK3_MK:=

.  include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pycurses+=	${PYPKGPREFIX}-curses-[0-9]*
BUILDLINK_ABI_DEPENDS.pycurses+=	${PYPKGPREFIX}-curses>=0nb4
BUILDLINK_PKGSRCDIR.pycurses?=	../../devel/py-curses

.include "../../devel/ncurses/buildlink3.mk"
.endif # PY_CURSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-pycurses
