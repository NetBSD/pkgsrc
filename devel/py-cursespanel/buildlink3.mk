# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:08:51 joerg Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_CURSESPANEL_BUILDLINK3_MK:=	${PY_CURSESPANEL_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pycursespanel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npycursespanel}
BUILDLINK_PACKAGES+=	pycursespanel

.if !empty(PY_CURSESPANEL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pycursespanel+=	${PYPKGPREFIX}-cursespanel-[0-9]*
BUILDLINK_RECOMMENDED.pycursespanel?=	${PYPKGPREFIX}-cursespanel>=0nb3
BUILDLINK_PKGSRCDIR.pycursespanel?=	../../devel/py-cursespanel
.endif	# PY_CURSESPANEL_BUILDLINK3_MK

.include "../../devel/ncurses/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
