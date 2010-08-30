# $NetBSD: buildlink3.mk,v 1.11 2010/08/30 17:27:11 drochner Exp $

BUILDLINK_TREE+=	librfuncs

.if !defined(LIBRFUNCS_BUILDLINK3_MK)
LIBRFUNCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librfuncs+=	librfuncs>=1.0.4
BUILDLINK_PKGSRCDIR.librfuncs?=	../../devel/librfuncs
.endif # LIBRFUNCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-librfuncs
