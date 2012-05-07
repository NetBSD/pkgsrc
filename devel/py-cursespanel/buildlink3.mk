# $NetBSD: buildlink3.mk,v 1.9 2012/05/07 01:53:27 dholland Exp $

BUILDLINK_TREE+=	pycursespanel

.if !defined(PY_CURSESPANEL_BUILDLINK3_MK)
PY_CURSESPANEL_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pycursespanel+=	${PYPKGPREFIX}-cursespanel-[0-9]*
BUILDLINK_ABI_DEPENDS.pycursespanel+=	${PYPKGPREFIX}-cursespanel>=0nb3
BUILDLINK_PKGSRCDIR.pycursespanel?=	../../devel/py-cursespanel

.include "../../devel/ncurses/buildlink3.mk"
.endif # PY_CURSESPANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-pycursespanel
