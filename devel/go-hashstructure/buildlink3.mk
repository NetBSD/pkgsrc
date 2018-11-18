# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:02:08 ryoon Exp $

BUILDLINK_TREE+=	go-hashstructure

.if !defined(GO_HASHSTRUCTURE_BUILDLINK3_MK)
GO_HASHSTRUCTURE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-hashstructure=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-hashstructure?=		build

BUILDLINK_API_DEPENDS.go-hashstructure+=	go-hashstructure>=1.0.0
BUILDLINK_PKGSRCDIR.go-hashstructure?=		../../devel/go-hashstructure
.endif	# GO_HASHSTRUCTURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-hashstructure
