# $NetBSD: buildlink3.mk,v 1.1 2016/07/22 02:45:44 cheusov Exp $

BUILDLINK_TREE+=	classias

.if !defined(CLASSIAS_BUILDLINK3_MK)
CLASSIAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.classias+=	classias>=1.1.0
BUILDLINK_PKGSRCDIR.classias?=	../../math/classias
.endif # CLASSIAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-classias
