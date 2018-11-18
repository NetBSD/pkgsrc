# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 07:51:51 ryoon Exp $

BUILDLINK_TREE+=	go-humanize

.if !defined(GO_HUMANIZE_BUILDLINK3_MK)
GO_HUMANIZE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-humanize=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-humanize?=	build

BUILDLINK_API_DEPENDS.go-humanize+=	go-humanize>=1.0.0
BUILDLINK_PKGSRCDIR.go-humanize?=	../../devel/go-humanize
.endif	# GO_HUMANIZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-humanize
