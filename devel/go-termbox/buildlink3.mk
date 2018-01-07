# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:02 rillig Exp $

BUILDLINK_TREE+=	go-termbox

.if !defined(GO_TERMBOX_BUILDLINK3_MK)
GO_TERMBOX_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-termbox=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-termbox?=	build

BUILDLINK_API_DEPENDS.go-termbox+=	go-termbox>=20160808
BUILDLINK_PKGSRCDIR.go-termbox?=	../../devel/go-termbox

.include "../../textproc/go-runewidth/buildlink3.mk"
.endif	# GO_TERMBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-termbox
