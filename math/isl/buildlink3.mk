# $NetBSD: buildlink3.mk,v 1.1 2013/02/17 22:10:47 wiz Exp $

BUILDLINK_TREE+=	isl

.if !defined(ISL_BUILDLINK3_MK)
ISL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.isl+=	isl>=0.11.1
BUILDLINK_PKGSRCDIR.isl?=	../../math/isl

.endif # ISL_BUILDLINK3_MK

BUILDLINK_TREE+=	-isl
