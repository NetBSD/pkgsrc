# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:14 jperkin Exp $

BUILDLINK_TREE+=	go-md2man

.if !defined(GO_MD2MAN_BUILDLINK3_MK)
GO_MD2MAN_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-md2man=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-md2man?=		build

BUILDLINK_API_DEPENDS.go-md2man+=	go-md2man>=1.0.6
BUILDLINK_PKGSRCDIR.go-md2man?=		../../textproc/go-md2man

.include "../../devel/go-blackfriday/buildlink3.mk"
.include "../../devel/go-sanitized_anchor_name/buildlink3.mk"
.endif  # GO_MD2MAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-md2man
