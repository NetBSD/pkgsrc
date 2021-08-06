# $NetBSD: buildlink3.mk,v 1.1 2021/08/06 00:49:20 sjmulder Exp $

BUILDLINK_TREE+=	mustach

.if !defined(MUSTACH_BUILDLINK3_MK)
MUSTACH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mustach+=	mustach>=1.1.0
BUILDLINK_PKGSRCDIR.mustach?=	../../devel/mustach

.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-mustach
