# $NetBSD: buildlink3.mk,v 1.1 2020/06/29 12:40:53 nikita Exp $

BUILDLINK_TREE+=	go-gift

.if !defined(GO_GIFT_BUILDLINK3_MK)
GO_GIFT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gift=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gift?=		build

BUILDLINK_API_DEPENDS.go-gift+=		go-gift>=1.2.1
BUILDLINK_PKGSRCDIR.go-gift?=		../../graphics/go-gift

.endif	# GO_GIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gift
