# $NetBSD: buildlink3.mk,v 1.2 2018/03/11 20:38:25 bsiegert Exp $

BUILDLINK_TREE+=	go-sys

.if !defined(GO_SYS_BUILDLINK3_MK)
GO_SYS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-sys= ${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-sys?=	build

BUILDLINK_API_DEPENDS.go-sys+=	go-sys>=0.0.20180101
BUILDLINK_PKGSRCDIR.go-sys?=	../../devel/go-sys
.endif	# GO_SYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-sys
