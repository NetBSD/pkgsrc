# $NetBSD: buildlink3.mk,v 1.1 2016/08/13 20:21:08 bsiegert Exp $

BUILDLINK_TREE+=	go-runewidth

.if !defined(GO_RUNEWIDTH_BUILDLINK3_MK)
GO_RUNEWIDTH_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-runewidth=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-runewidth?=		build

BUILDLINK_API_DEPENDS.go-runewidth+=	go-runewidth>=0.0.1
BUILDLINK_PKGSRCDIR.go-runewidth?=	../../textproc/go-runewidth
.endif	# GO_RUNEWIDTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-runewidth
