# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:22 rillig Exp $

BUILDLINK_TREE+=	go-stats

.if !defined(GO_STATS_BUILDLINK3_MK)
GO_STATS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-stats=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-stats?=		build

BUILDLINK_API_DEPENDS.go-stats+=	go-stats>=0.0
BUILDLINK_PKGSRCDIR.go-stats?=		../../math/go-stats

.endif  # GO_STATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-stats
