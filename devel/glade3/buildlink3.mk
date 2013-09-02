# $NetBSD: buildlink3.mk,v 1.22 2013/09/02 19:50:45 adam Exp $

BUILDLINK_TREE+=	glade3

.if !defined(GLADE3_BUILDLINK3_MK)
GLADE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glade3+=	glade3>=3.4.0
BUILDLINK_ABI_DEPENDS.glade3+=	glade3>=3.4.5nb25
BUILDLINK_PKGSRCDIR.glade3?=	../../devel/glade3

.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # GLADE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-glade3
