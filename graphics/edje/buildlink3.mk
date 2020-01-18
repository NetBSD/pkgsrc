# $NetBSD: buildlink3.mk,v 1.26 2020/01/18 21:48:11 jperkin Exp $

BUILDLINK_TREE+=	edje

.if !defined(EDJE_BUILDLINK3_MK)
EDJE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edje+=	edje>=1.7.7
BUILDLINK_ABI_DEPENDS.edje?=	edje>=1.7.7nb22
BUILDLINK_PKGSRCDIR.edje?=	../../graphics/edje

.include	"../../devel/ecore/buildlink3.mk"
.include	"../../devel/eet/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../lang/embryo/buildlink3.mk"
.include	"../../lang/lua/buildlink3.mk"
.endif # EDJE_BUILDLINK3_MK

BUILDLINK_TREE+=	-edje
