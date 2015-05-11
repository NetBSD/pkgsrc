# $NetBSD: buildlink3.mk,v 1.1 2015/05/11 13:02:21 bsiegert Exp $

BUILDLINK_TREE+=	gcloud-golang-metadata

.if !defined(GCLOUD_GOLANG_METADATA_BUILDLINK3_MK)
GCLOUD_GOLANG_METADATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcloud-golang-metadata+=	gcloud-golang-metadata>=20150310
BUILDLINK_PKGSRCDIR.gcloud-golang-metadata?=	../../net/gcloud-golang-metadata
BUILDLINK_DEPMETHOD.gcloud-golang-metadata?=	build

.include "../../net/go-net/buildlink3.mk"
.endif	# GCLOUD_GOLANG_METADATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcloud-golang-metadata
