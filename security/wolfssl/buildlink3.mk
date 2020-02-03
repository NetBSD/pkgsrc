# $NetBSD: buildlink3.mk,v 1.1 2020/02/03 23:04:09 fox Exp $

BUILDLINK_TREE+=	wolfssl

.if !defined(WOLFSSL_BUILDLINK3_MK)
WOLFSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wolfssl+=	wolfssl>=4.3.0
BUILDLINK_PKGSRCDIR.wolfssl?=	../../security/wolfssl

.endif # WOLFSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-wolfssl
