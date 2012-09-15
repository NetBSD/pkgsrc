# $NetBSD: buildlink3.mk,v 1.7 2012/09/15 10:05:17 obache Exp $

BUILDLINK_TREE+=	tomoe

.if !defined(TOMOE_BUILDLINK3_MK)
TOMOE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tomoe+=	tomoe>=0.6.0
BUILDLINK_ABI_DEPENDS.tomoe+=	tomoe>=0.6.0nb5
BUILDLINK_PKGSRCDIR.tomoe?=	../../inputmethod/tomoe

.include "../../devel/glib2/buildlink3.mk"
.endif # TOMOE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tomoe
