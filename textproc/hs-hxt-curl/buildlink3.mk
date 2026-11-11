# $NetBSD: buildlink3.mk,v 1.9 2026/11/11 11:55:54 wiz Exp $

BUILDLINK_TREE+=	hs-hxt-curl

.if !defined(HS_HXT_CURL_BUILDLINK3_MK)
HS_HXT_CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-curl+=	hs-hxt-curl>=9.1.1
BUILDLINK_ABI_DEPENDS.hs-hxt-curl+=	hs-hxt-curl>=9.1.1.1nb8
BUILDLINK_PKGSRCDIR.hs-hxt-curl?=	../../textproc/hs-hxt-curl

.include "../../www/hs-curl/buildlink3.mk"
.include "../../textproc/hs-hxt/buildlink3.mk"
.endif	# HS_HXT_CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-curl
