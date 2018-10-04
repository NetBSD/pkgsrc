# $NetBSD: buildlink3.mk,v 1.5 2018/10/04 12:53:07 adam Exp $

BUILDLINK_TREE+=	jansson

.if !defined(JANSSON_BUILDLINK3_MK)
JANSSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jansson+=	jansson>=2.0
BUILDLINK_ABI_DEPENDS.jansson+=	jansson>=2.4nb1
BUILDLINK_PKGSRCDIR.jansson?=	../../textproc/jansson

.endif # JANSSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-jansson
