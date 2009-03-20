# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 17:30:10 joerg Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_CURSESPANEL_BUILDLINK3_MK:=	${PY_CURSESPANEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pycursespanel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npycursespanel}
BUILDLINK_PACKAGES+=	pycursespanel
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pycursespanel

.if !empty(PY_CURSESPANEL_BUILDLINK3_MK:M+)
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pycursespanel+=	${PYPKGPREFIX}-cursespanel-[0-9]*
BUILDLINK_ABI_DEPENDS.pycursespanel?=	${PYPKGPREFIX}-cursespanel>=0nb3
BUILDLINK_PKGSRCDIR.pycursespanel?=	../../devel/py-cursespanel
.endif	# PY_CURSESPANEL_BUILDLINK3_MK

.include "../../devel/ncurses/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
