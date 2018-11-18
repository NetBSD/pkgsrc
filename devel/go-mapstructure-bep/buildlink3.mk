# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:06:21 ryoon Exp $

BUILDLINK_TREE+=	go-mapstructure-bep

.if !defined(GO_MAPSTRUCTURE_BEP_BUILDLINK3_MK)
GO_MAPSTRUCTURE_BEP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-mapstructure-bep=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-mapstructure-bep?=	build

BUILDLINK_API_DEPENDS.go-mapstructure-bep+=	go-mapstructure-bep>=0.0
BUILDLINK_PKGSRCDIR.go-mapstructure-bep?=	../../devel/go-mapstructure-bep

.endif  # GO_MAPSTRUCTURE_BEP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-mapstructure-bep
