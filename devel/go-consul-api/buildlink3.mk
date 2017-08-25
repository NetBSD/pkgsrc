# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-consul-api

.if !defined(GO_CONSUL_API_BUILDLINK3_MK)
GO_CONSUL_API_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-consul-api=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-consul-api?=		build

BUILDLINK_API_DEPENDS.go-consul-api+=		go-consul-api>=0.0
BUILDLINK_PKGSRCDIR.go-consul-api?=		../../devel/go-consul-api

.endif  # GO_CONSUL_API_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-consul-api
