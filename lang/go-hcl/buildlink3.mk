# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:14 jperkin Exp $

BUILDLINK_TREE+=	go-hcl

.if !defined(GO_HCL_BUILDLINK3_MK)
GO_HCL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-hcl=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-hcl?=		build

BUILDLINK_API_DEPENDS.go-hcl+=		go-hcl>=0.0
BUILDLINK_PKGSRCDIR.go-hcl?=		../../lang/go-hcl

.endif  # GO_HCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-hcl
