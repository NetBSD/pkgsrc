# $NetBSD: buildlink3.mk,v 1.1 2024/08/20 15:29:32 bsiegert Exp $

BUILDLINK_TREE+=	efivar

.if !defined(EFIVAR_BUILDLINK3_MK)
EFIVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efivar+=	efivar>=38
BUILDLINK_PKGSRCDIR.efivar?=	../../devel/efivar
.endif	# EFIVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-efivar
