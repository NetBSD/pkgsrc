# $NetBSD: buildlink3.mk,v 1.1 2017/10/24 06:50:54 maya Exp $

BUILDLINK_TREE+=	go-runewidth

.if !defined(GO_RUNEWIDTH_BUILDLINK3_MK)
GO_RUNEWIDTH_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-runewidth=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-runewidth?=	build

BUILDLINK_API_DEPENDS.go-runewidth+=	go-runewidth>=0.0
BUILDLINK_PKGSRCDIR.go-runewidth?=	../../devel/go-runewidth

.endif  # GO_RUNEWIDTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-runewidth
