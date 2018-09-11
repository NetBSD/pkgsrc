# $NetBSD: buildlink3.mk,v 1.1 2018/09/11 00:08:06 minskim Exp $

BUILDLINK_TREE+=	go-colortext

.if !defined(GO_COLORTEXT_BUILDLINK3_MK)
GO_COLORTEXT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-colortext=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-colortext?=	build

BUILDLINK_API_DEPENDS.go-colortext+=	go-colortext>=1.0.0
BUILDLINK_PKGSRCDIR.go-colortext?=	../../devel/go-colortext
.endif	# GO_COLORTEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-colortext
