# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:36:26 gavan Exp $

BUILDLINK_TREE+=	go-pflag

.if !defined(GO_PFLAG_BUILDLINK3_MK)
GO_PFLAG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pflag=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pflag?=		build

BUILDLINK_API_DEPENDS.go-pflag+=	go-pflag>=1.0.0
BUILDLINK_PKGSRCDIR.go-pflag?=		../../devel/go-pflag

.endif  # GO_PFLAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pflag

