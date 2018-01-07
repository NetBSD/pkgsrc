# $NetBSD: buildlink3.mk,v 1.12 2018/01/07 13:04:06 rillig Exp $

BUILDLINK_TREE+=	librfuncs

.if !defined(LIBRFUNCS_BUILDLINK3_MK)
LIBRFUNCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librfuncs+=	librfuncs>=1.0.4
BUILDLINK_PKGSRCDIR.librfuncs?=		../../devel/librfuncs
.endif # LIBRFUNCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-librfuncs
