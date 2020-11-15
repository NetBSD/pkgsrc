# $NetBSD: buildlink3.mk,v 1.1 2020/11/15 21:01:22 schmonz Exp $

BUILDLINK_TREE+=	bearssl

.if !defined(BEARSSL_BUILDLINK3_MK)
BEARSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bearssl+=	bearssl>=0.6nb1
BUILDLINK_PKGSRCDIR.bearssl?=	../../security/bearssl
.endif	# BEARSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-bearssl
