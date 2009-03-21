# $NetBSD: buildlink3.mk,v 1.3 2009/03/21 18:03:42 ahoka Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.5.7nb1
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

.include "../../devel/glib2/buildlink3.mk"
.endif # VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
