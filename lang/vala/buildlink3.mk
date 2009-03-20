# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:53 joerg Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.5.7
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

.include "../../devel/glib2/buildlink3.mk"
.endif # VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
