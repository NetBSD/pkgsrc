# $NetBSD: buildlink3.mk,v 1.1.1.1 2017/09/29 06:14:39 alnsn Exp $

BUILDLINK_TREE+=	go-siphash

.if !defined(GO_SIPHASH_BUILDLINK3_MK)
GO_SIPHASH_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-siphash=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-siphash?=		build

BUILDLINK_API_DEPENDS.go-siphash+=	go-siphash>=1.0.0
BUILDLINK_PKGSRCDIR.go-siphash?=	../../devel/go-siphash
.endif	# GO_SIPHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-siphash
