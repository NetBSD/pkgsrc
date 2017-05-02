# $NetBSD: buildlink3.mk,v 1.1 2017/05/02 17:00:53 fhajny Exp $

BUILDLINK_TREE+=	go-sys

.if !defined(GO_SYS_BUILDLINK3_MK)
GO_SYS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-sys= ${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-sys?=	build

BUILDLINK_API_DEPENDS.go-sys+=	go-sys>=0.0.0
BUILDLINK_PKGSRCDIR.go-sys?=	../../devel/go-sys
.endif	# GO_SYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-sys
