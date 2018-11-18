# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 07:54:48 ryoon Exp $

BUILDLINK_TREE+=	go-kingpin.v3-unstable

.if !defined(GO_KINGPIN.V3_UNSTABLE_BUILDLINK3_MK)
GO_KINGPIN.V3_UNSTABLE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-kingpin.v3-unstable=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-kingpin.v3-unstable?=		build

BUILDLINK_API_DEPENDS.go-kingpin.v3-unstable+=	go-kingpin.v3-unstable>=3.0.0.0.20100811
BUILDLINK_PKGSRCDIR.go-kingpin.v3-unstable?=	../../devel/go-kingpin.v3-unstable

.endif	# GO_KINGPIN.V3_UNSTABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-kingpin.v3-unstable
