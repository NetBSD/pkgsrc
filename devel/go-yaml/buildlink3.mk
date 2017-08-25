# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:14 jperkin Exp $

BUILDLINK_TREE+=	go-yaml

.if !defined(GO_YAML_BUILDLINK3_MK)
GO_YAML_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-yaml=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-yaml?=		build

BUILDLINK_API_DEPENDS.go-yaml+=		go-yaml>=0.0
BUILDLINK_PKGSRCDIR.go-yaml?=		../../devel/go-yaml

.endif  # GO_YAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-yaml
