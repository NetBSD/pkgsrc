# $NetBSD: buildlink3.mk,v 1.3 2019/11/02 22:37:58 rillig Exp $

BUILDLINK_TREE+=	go-image

.if !defined(GO_IMAGE_BUILDLINK3_MK)
GO_IMAGE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-image=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-image?=		build

BUILDLINK_API_DEPENDS.go-image+=	go-image>=20170405
BUILDLINK_PKGSRCDIR.go-image?=		../../graphics/go-image

.include "../../textproc/go-text/buildlink3.mk"
.endif	# GO_IMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-image
