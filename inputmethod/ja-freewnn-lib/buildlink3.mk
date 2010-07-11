# $NetBSD: buildlink3.mk,v 1.8 2010/07/11 02:53:24 obache Exp $

BUILDLINK_TREE+=	ja-FreeWnn-lib

.if !defined(JA_FREEWNN_LIB_BUILDLINK3_MK)
JA_FREEWNN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ja-FreeWnn-lib+=	ja-FreeWnn-lib>=1.10nb4
BUILDLINK_PKGSRCDIR.ja-FreeWnn-lib?=	../../inputmethod/ja-freewnn-lib
BUILDLINK_DEPMETHOD.ja-freewnn?=	build
.endif # JA_FREEWNN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ja-FreeWnn-lib
