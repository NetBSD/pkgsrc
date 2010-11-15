# $NetBSD: buildlink3.mk,v 1.6 2010/11/15 22:56:38 abs Exp $

BUILDLINK_TREE+=	glade3

.if !defined(GLADE3_BUILDLINK3_MK)
GLADE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glade3+=	glade3>=3.4.0
BUILDLINK_ABI_DEPENDS.glade3?=	glade3>=3.4.5nb5
BUILDLINK_PKGSRCDIR.glade3?=	../../devel/glade3

.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # GLADE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-glade3
