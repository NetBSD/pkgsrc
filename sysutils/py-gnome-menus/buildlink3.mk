# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:26 joerg Exp $

BUILDLINK_TREE+=	py-gnome-menus

.if !defined(PY_GNOME_MENUS_BUILDLINK3_MK)
PY_GNOME_MENUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-gnome-menus+=	${PYPKGPREFIX}-gnome-menus>=2.16.1
BUILDLINK_PKGSRCDIR.py-gnome-menus?=	../../sysutils/py-gnome-menus
.endif # PY_GNOME_MENUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gnome-menus
