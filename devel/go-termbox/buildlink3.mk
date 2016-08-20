# $NetBSD: buildlink3.mk,v 1.1 2016/08/20 09:30:41 bsiegert Exp $

BUILDLINK_TREE+=	go-termbox

.if !defined(GO_TERMBOX_BUILDLINK3_MK)
GO_TERMBOX_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-termbox=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-termbox?=		build

BUILDLINK_API_DEPENDS.go-termbox+=	go-termbox>=20160808
BUILDLINK_PKGSRCDIR.go-termbox?=	../../devel/go-termbox

.include "../../textproc/go-runewidth/buildlink3.mk"
.endif	# GO_TERMBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-termbox
