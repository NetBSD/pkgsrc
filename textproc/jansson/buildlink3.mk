# $NetBSD: buildlink3.mk,v 1.2 2014/02/12 23:18:41 tron Exp $

BUILDLINK_TREE+=	jansson

.if !defined(JANSSON_BUILDLINK3_MK)
JANSSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jansson+=jansson>=2.0
BUILDLINK_ABI_DEPENDS.jansson?=	jansson>=2.4nb1
BUILDLINK_PKGSRCDIR.jansson?=	../../textproc/jansson

.include "../../security/openssl/buildlink3.mk"
.endif # JANSSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-jansson
