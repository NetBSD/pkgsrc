# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:21 joerg Exp $

BUILDLINK_TREE+=	librfuncs

.if !defined(LIBRFUNCS_BUILDLINK3_MK)
LIBRFUNCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librfuncs+=	librfuncs>=1.0.4
BUILDLINK_PKGSRCDIR.librfuncs?=	../../devel/librfuncs
BUILDLINK_LDFLAGS.librfuncs+=	-lrfuncs
.endif # LIBRFUNCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-librfuncs
