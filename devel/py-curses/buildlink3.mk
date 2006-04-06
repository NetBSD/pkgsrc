# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 06:21:55 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_CURSES_BUILDLINK3_MK:=	${PY_CURSES_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pycurses
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npycurses}
BUILDLINK_PACKAGES+=	pycurses

.if !empty(PY_CURSES_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pycurses+=	${PYPKGPREFIX}-curses-[0-9]*
BUILDLINK_ABI_DEPENDS.pycurses?=	${PYPKGPREFIX}-curses>=0nb4
BUILDLINK_PKGSRCDIR.pycurses?=	../../devel/py-curses
.endif	# PY_CURSES_BUILDLINK3_MK

.include "../../devel/ncurses/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
