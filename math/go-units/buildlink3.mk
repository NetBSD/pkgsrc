# $NetBSD: buildlink3.mk,v 1.1 2018/06/17 01:11:11 minskim Exp $

BUILDLINK_TREE+=	go-units

.if !defined(GO_UNITS_BUILDLINK3_MK)
GO_UNITS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-units=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-units?=		build

BUILDLINK_API_DEPENDS.go-units+=	go-units>=0.0.20151021
BUILDLINK_PKGSRCDIR.go-units?=		../../math/go-units
.endif	# GO_UNITS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-units
