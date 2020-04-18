# $NetBSD: buildlink3.mk,v 1.1 2020/04/18 15:56:36 nikita Exp $

BUILDLINK_TREE+=	go-radix

.if !defined(GO_RADIX_BUILDLINK3_MK)
GO_RADIX_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-radix=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-radix?=		build

BUILDLINK_API_DEPENDS.go-radix+=	go-radix>=1.0.0
BUILDLINK_PKGSRCDIR.go-radix?=		../../devel/go-radix
.endif  # GO_RADIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-radix
