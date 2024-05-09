# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:32:31 pho Exp $

BUILDLINK_TREE+=	hs-uri-encode

.if !defined(HS_URI_ENCODE_BUILDLINK3_MK)
HS_URI_ENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uri-encode+=	hs-uri-encode>=1.5.0
BUILDLINK_ABI_DEPENDS.hs-uri-encode+=	hs-uri-encode>=1.5.0.7nb5
BUILDLINK_PKGSRCDIR.hs-uri-encode?=	../../net/hs-uri-encode

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_URI_ENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uri-encode
