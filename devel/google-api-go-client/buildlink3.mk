# $NetBSD: buildlink3.mk,v 1.1 2015/05/11 14:28:43 bsiegert Exp $

BUILDLINK_TREE+=	google-api-go-client

.if !defined(GOOGLE_API_GO_CLIENT_BUILDLINK3_MK)
GOOGLE_API_GO_CLIENT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.google-api-go-client?=	build
BUILDLINK_API_DEPENDS.google-api-go-client+=	google-api-go-client>=20150507
BUILDLINK_PKGSRCDIR.google-api-go-client?=	../../devel/google-api-go-client

.include "../../security/go-oauth2/buildlink3.mk"
.endif	# GOOGLE_API_GO_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-google-api-go-client
