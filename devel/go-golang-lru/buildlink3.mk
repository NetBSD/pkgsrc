# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:13 jperkin Exp $

BUILDLINK_TREE+=	go-golang-lru

.if !defined(GO_GOLANG_LRU_BUILDLINK3_MK)
GO_GOLANG_LRU_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-golang-lru=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-golang-lru?=		build

BUILDLINK_API_DEPENDS.go-golang-lru+=		go-golang-lru>=0.0
BUILDLINK_PKGSRCDIR.go-golang-lru?=		../../devel/go-golang-lru

.endif  # GO_GOLANG_LRU_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-golang-lru
