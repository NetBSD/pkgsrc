# $NetBSD: buildlink3.mk,v 1.2 2020/01/02 22:57:40 wiz Exp $

BUILDLINK_TREE+=	go-xerrors

.if !defined(GO_XERRORS_BUILDLINK3_MK)
GO_XERRORS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-xerrors=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-xerrors?=	build

BUILDLINK_API_DEPENDS.go-xerrors+=	go-xerrors>=20190719
BUILDLINK_PKGSRCDIR.go-xerrors?=	../../devel/go-xerrors
.endif	# GO_XERRORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-xerrors
