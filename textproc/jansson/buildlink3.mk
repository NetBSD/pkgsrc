# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:33 rillig Exp $

BUILDLINK_TREE+=	jansson

.if !defined(JANSSON_BUILDLINK3_MK)
JANSSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jansson+=	jansson>=2.0
BUILDLINK_ABI_DEPENDS.jansson?=	jansson>=2.4nb1
BUILDLINK_PKGSRCDIR.jansson?=	../../textproc/jansson

.endif # JANSSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-jansson
