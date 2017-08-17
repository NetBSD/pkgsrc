# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:34:01 gavan Exp $

BUILDLINK_TREE+=	go-nitro

.if !defined(GO_NITRO_BUILDLINK3_MK)
GO_NITRO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-nitro=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-nitro?=		build

BUILDLINK_API_DEPENDS.go-nitro+=	go-nitro>=0.0
BUILDLINK_PKGSRCDIR.go-nitro?=		../../devel/go-nitro

.endif  # GO_NITRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-nitro

