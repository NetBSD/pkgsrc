# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:26 rillig Exp $

BUILDLINK_TREE+=	flickcurl

.if !defined(FLICKCURL_BUILDLINK3_MK)
FLICKCURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flickcurl+=	flickcurl>=1.21
BUILDLINK_ABI_DEPENDS.flickcurl+=	flickcurl>=1.22nb1
BUILDLINK_PKGSRCDIR.flickcurl?=		../../net/flickcurl

.endif	# FLICKCURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-flickcurl
