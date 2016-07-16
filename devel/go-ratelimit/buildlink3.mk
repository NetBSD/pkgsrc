# $NetBSD: buildlink3.mk,v 1.1 2016/07/16 12:51:46 bsiegert Exp $

BUILDLINK_TREE+=	go-ratelimit

.if !defined(GO_RATELIMIT_BUILDLINK3_MK)
GO_RATELIMIT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ratelimit=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ratelimit?=		build

BUILDLINK_API_DEPENDS.go-ratelimit+=	go-ratelimit>=0.0.20151125
BUILDLINK_PKGSRCDIR.go-ratelimit?=	../../devel/go-ratelimit

.endif	# GO_RATELIMIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ratelimit
