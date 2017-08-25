# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:13 jperkin Exp $

BUILDLINK_TREE+=	go-pflag

.if !defined(GO_PFLAG_BUILDLINK3_MK)
GO_PFLAG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pflag=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pflag?=		build

BUILDLINK_API_DEPENDS.go-pflag+=	go-pflag>=1.0.0
BUILDLINK_PKGSRCDIR.go-pflag?=		../../devel/go-pflag

.endif  # GO_PFLAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pflag
