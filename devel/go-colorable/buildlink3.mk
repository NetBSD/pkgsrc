# $NetBSD: buildlink3.mk,v 1.1 2018/07/22 22:42:43 minskim Exp $

BUILDLINK_TREE+=	go-colorable

.if !defined(GO_COLORABLE_BUILDLINK3_MK)
GO_COLORABLE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-colorable=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-colorable?=	build

BUILDLINK_API_DEPENDS.go-colorable+=	go-colorable>=0.0.9
BUILDLINK_PKGSRCDIR.go-colorable?=	../../devel/go-colorable

.include "../../devel/go-isatty/buildlink3.mk"
.endif	# GO_COLORABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-colorable
