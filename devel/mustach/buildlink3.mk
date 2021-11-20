# $NetBSD: buildlink3.mk,v 1.2 2021/11/20 00:31:10 sjmulder Exp $

BUILDLINK_TREE+=	mustach

.if !defined(MUSTACH_BUILDLINK3_MK)
MUSTACH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mustach+=	mustach>=1.2.2
BUILDLINK_PKGSRCDIR.mustach?=	../../devel/mustach

.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-mustach
