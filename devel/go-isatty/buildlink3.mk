# $NetBSD: buildlink3.mk,v 1.1 2017/10/24 06:55:07 maya Exp $

BUILDLINK_TREE+=	go-isatty

.if !defined(GO_ISATTY_BUILDLINK3_MK)
GO_ISATTY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-isatty=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-isatty?=		build

BUILDLINK_API_DEPENDS.go-isatty+=	go-isatty>=0.0
BUILDLINK_PKGSRCDIR.go-isatty?=		../../devel/go-isatty

.endif  # GO_ISATTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-isatty
