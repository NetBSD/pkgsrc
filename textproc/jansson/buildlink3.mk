# $NetBSD: buildlink3.mk,v 1.1 2013/11/27 01:54:19 mef Exp $

BUILDLINK_TREE+=	jansson

.if !defined(JANSSON_BUILDLINK3_MK)
JANSSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jansson+=jansson>=2.0
BUILDLINK_PKGSRCDIR.jansson?=	../../textproc/jansson

.include "../../security/openssl/buildlink3.mk"
.endif # JANSSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-jansson
