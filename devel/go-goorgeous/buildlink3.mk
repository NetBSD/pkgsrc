# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:28:07 gavan Exp $

BUILDLINK_TREE+=	go-goorgeous

.if !defined(GO_GOORGEOUS_BUILDLINK3_MK)
GO_GOORGEOUS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-goorgeous=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-goorgeous?=		build

BUILDLINK_API_DEPENDS.go-goorgeous+=		go-goorgeous>=0.0
BUILDLINK_PKGSRCDIR.go-goorgeous?=		../../devel/go-goorgeous

.endif  # GO_GOORGEOUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-goorgeous

