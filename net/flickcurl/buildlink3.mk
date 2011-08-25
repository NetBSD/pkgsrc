# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/08/25 13:30:23 jakllsch Exp $

BUILDLINK_TREE+=	flickcurl

.if !defined(FLICKCURL_BUILDLINK3_MK)
FLICKCURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flickcurl+=	flickcurl>=1.21
BUILDLINK_PKGSRCDIR.flickcurl?=	../../net/flickcurl

.endif	# FLICKCURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-flickcurl
