# $NetBSD: buildlink3.mk,v 1.1 2019/11/06 11:26:49 ng0 Exp $

BUILDLINK_TREE+=	go-xxhash

.if !defined(GO_XXHASH_BUILDLINK3_MK)
GO_XXHASH_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-xxhash=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-xxhash?=		build

BUILDLINK_API_DEPENDS.go-xxhash+=	go-xxhash>=2.0.0
BUILDLINK_PKGSRCDIR.go-xxhash?=		../../security/go-xxhash
.endif	# GO_XXHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-xxhash
