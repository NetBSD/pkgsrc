# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:22 rillig Exp $

BUILDLINK_TREE+=	classias

.if !defined(CLASSIAS_BUILDLINK3_MK)
CLASSIAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.classias+=	classias>=1.1.0
BUILDLINK_PKGSRCDIR.classias?=		../../math/classias
.endif # CLASSIAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-classias
