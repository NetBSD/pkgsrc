# $NetBSD: buildlink3.mk,v 1.1 2018/07/19 12:36:17 minskim Exp $

BUILDLINK_TREE+=	go-smartcrop

.if !defined(GO_SMARTCROP_BUILDLINK3_MK)
GO_SMARTCROP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-smartcrop=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-smartcrop?=	build

BUILDLINK_API_DEPENDS.go-smartcrop+=	go-smartcrop>=0.2.0.20180227
BUILDLINK_PKGSRCDIR.go-smartcrop?=	../../graphics/go-smartcrop

.include "../../graphics/go-image/buildlink3.mk"
.include "../../graphics/go-resize/buildlink3.mk"
.endif	# GO_SMARTCROP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-smartcrop
