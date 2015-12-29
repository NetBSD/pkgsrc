# $NetBSD: buildlink3.mk,v 1.2 2015/12/29 21:47:48 bsiegert Exp $

BUILDLINK_TREE+=	go-oauth2

.if !defined(GO_OAUTH2_BUILDLINK3_MK)
GO_OAUTH2_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-oauth2= ${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-oauth2?=	build
BUILDLINK_API_DEPENDS.go-oauth2+=	go-oauth2>=20150310
BUILDLINK_PKGSRCDIR.go-oauth2?=	../../security/go-oauth2

.include "../../textproc/go-text/buildlink3.mk"
.include "../../net/gcloud-golang-metadata/buildlink3.mk"
.endif	# GO_OAUTH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-oauth2
