# $NetBSD: buildlink3.mk,v 1.2 2015/12/29 21:47:48 bsiegert Exp $

BUILDLINK_TREE+=	gcloud-golang-metadata

.if !defined(GCLOUD_GOLANG_METADATA_BUILDLINK3_MK)
GCLOUD_GOLANG_METADATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcloud-golang-metadata+=	gcloud-golang-metadata>=20150310
BUILDLINK_PKGSRCDIR.gcloud-golang-metadata?=	../../net/gcloud-golang-metadata
BUILDLINK_DEPMETHOD.gcloud-golang-metadata?=	build
BUILDLINK_CONTENTS_FILTER.gcloud-golang-metadata= ${EGREP} gopkg/

.include "../../net/go-net/buildlink3.mk"
.endif	# GCLOUD_GOLANG_METADATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcloud-golang-metadata
