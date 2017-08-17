# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:32:00 gavan Exp $

BUILDLINK_TREE+=	go-mapstructure

.if !defined(GO_MAPSTRUCTURE_BUILDLINK3_MK)
GO_MAPSTRUCTURE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-mapstructure=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-mapstructure?=	build

BUILDLINK_API_DEPENDS.go-mapstructure+=	go-mapstructure>=0.0
BUILDLINK_PKGSRCDIR.go-mapstructure?=	../../devel/go-mapstructure

.endif  # GO_MAPSTRUCTURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-mapstructure

