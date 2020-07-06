# $NetBSD: buildlink3.mk,v 1.2 2020/07/06 22:52:13 gutteridge Exp $

BUILDLINK_TREE+=	go-isatty

.if !defined(GO_ISATTY_BUILDLINK3_MK)
GO_ISATTY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-isatty=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-isatty?=		build

BUILDLINK_API_DEPENDS.go-isatty+=	go-isatty>=0.0
BUILDLINK_PKGSRCDIR.go-isatty?=		../../devel/go-isatty

.include "../../devel/go-sys/buildlink3.mk"
.endif  # GO_ISATTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-isatty
