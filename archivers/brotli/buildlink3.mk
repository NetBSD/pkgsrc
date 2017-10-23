# $NetBSD: buildlink3.mk,v 1.1 2017/10/23 13:15:29 adam Exp $

BUILDLINK_TREE+=	brotli

.if !defined(BROTLI_BUILDLINK3_MK)
BROTLI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brotli+=	brotli>=1.0.1
BUILDLINK_PKGSRCDIR.brotli?=	../../archivers/brotli
.endif	# BROTLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-brotli
