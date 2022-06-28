# $NetBSD: buildlink3.mk,v 1.15 2022/06/28 11:31:40 wiz Exp $

BUILDLINK_TREE+=	bglibs

.if !defined(BGLIBS_BUILDLINK3_MK)
BGLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bglibs+=	bglibs>=2.03
BUILDLINK_ABI_DEPENDS.bglibs?=	bglibs>=2.04nb5
BUILDLINK_PKGSRCDIR.bglibs?=	../../devel/bglibs
.endif # BGLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-bglibs
