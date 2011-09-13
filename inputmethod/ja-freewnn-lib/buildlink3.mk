# $NetBSD: buildlink3.mk,v 1.9 2011/09/13 07:23:16 mef Exp $

BUILDLINK_TREE+=	ja-FreeWnn-lib

.if !defined(JA_FREEWNN_LIB_BUILDLINK3_MK)
JA_FREEWNN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ja-FreeWnn-lib+=	ja-FreeWnn-lib>=1.11alpha22
BUILDLINK_PKGSRCDIR.ja-FreeWnn-lib?=	../../inputmethod/ja-freewnn-lib
.endif # JA_FREEWNN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ja-FreeWnn-lib
