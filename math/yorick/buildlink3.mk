# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:59 joerg Exp $

BUILDLINK_TREE+=	yorick

.if !defined(YORICK_BUILDLINK3_MK)
YORICK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yorick+=	yorick>=1.5.12
BUILDLINK_DEPMETHOD.yorick?=	build
BUILDLINK_ABI_DEPENDS.yorick?=	yorick>=1.6.02nb1
BUILDLINK_PKGSRCDIR.yorick?=	../../math/yorick
.endif # YORICK_BUILDLINK3_MK

BUILDLINK_TREE+=	-yorick
