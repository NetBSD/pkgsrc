# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:47 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_CURSESPANEL_BUILDLINK3_MK:=	${PY_CURSESPANEL_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pycursespanel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npycursespanel}
BUILDLINK_PACKAGES+=	pycursespanel
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pycursespanel

.if !empty(PY_CURSESPANEL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pycursespanel+=	${PYPKGPREFIX}-cursespanel-[0-9]*
BUILDLINK_ABI_DEPENDS.pycursespanel?=	${PYPKGPREFIX}-cursespanel>=0nb3
BUILDLINK_PKGSRCDIR.pycursespanel?=	../../devel/py-cursespanel
.endif	# PY_CURSESPANEL_BUILDLINK3_MK

.include "../../devel/ncurses/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
