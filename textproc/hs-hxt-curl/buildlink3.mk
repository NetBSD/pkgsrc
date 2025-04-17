# $NetBSD: buildlink3.mk,v 1.2 2025/04/17 21:52:34 wiz Exp $

BUILDLINK_TREE+=	hs-hxt-curl

.if !defined(HS_HXT_CURL_BUILDLINK3_MK)
HS_HXT_CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-curl+=	hs-hxt-curl>=9.1.1
BUILDLINK_ABI_DEPENDS.hs-hxt-curl+=	hs-hxt-curl>=9.1.1.1nb1
BUILDLINK_PKGSRCDIR.hs-hxt-curl?=	../../textproc/hs-hxt-curl

.include "../../www/hs-curl/buildlink3.mk"
.include "../../textproc/hs-hxt/buildlink3.mk"
.endif	# HS_HXT_CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-curl
