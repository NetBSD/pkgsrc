# $NetBSD: buildlink3.mk,v 1.1 2025/01/20 13:35:04 wiz Exp $

BUILDLINK_TREE+=	aklomp-base64

.if !defined(AKLOMP_BASE64_BUILDLINK3_MK)
AKLOMP_BASE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aklomp-base64+=	aklomp-base64>=0.5.2
BUILDLINK_PKGSRCDIR.aklomp-base64?=	../../converters/aklomp-base64
.endif	# AKLOMP_BASE64_BUILDLINK3_MK

BUILDLINK_TREE+=	-aklomp-base64
