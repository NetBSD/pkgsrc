# $NetBSD: buildlink3.mk,v 1.1 2015/03/10 19:57:18 bsiegert Exp $

BUILDLINK_TREE+=	go-text

.if !defined(GO_TEXT_BUILDLINK3_MK)
GO_TEXT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.go-text?=	build
BUILDLINK_API_DEPENDS.go-text+=	go-text>=20150310
BUILDLINK_PKGSRCDIR.go-text?=	../../textproc/go-text
.endif	# GO_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-text
