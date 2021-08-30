# $NetBSD: buildlink3.mk,v 1.2 2021/08/30 11:22:53 micha Exp $

BUILDLINK_TREE+=	isl

.if !defined(ISL_BUILDLINK3_MK)
ISL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.isl+=	isl>=0.11.1
BUILDLINK_PKGSRCDIR.isl?=	../../math/isl

.include "../../devel/gmp/buildlink3.mk"

.endif # ISL_BUILDLINK3_MK

BUILDLINK_TREE+=	-isl
