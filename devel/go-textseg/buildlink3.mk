# $NetBSD: buildlink3.mk,v 1.1 2020/04/27 15:42:20 nikita Exp $

BUILDLINK_TREE+=	go-textseg

.if !defined(GO_TEXTSEG_BUILDLINK3_MK)
GO_TEXTSEG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-textseg=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-textseg?=	build

BUILDLINK_API_DEPENDS.go-textseg+=	go-textseg>=12.0.0
BUILDLINK_PKGSRCDIR.go-textseg?=	../../devel/go-textseg

.endif	# GO_TEXTSEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-textseg
