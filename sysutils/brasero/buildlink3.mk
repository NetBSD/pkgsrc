# $NetBSD: buildlink3.mk,v 1.75 2024/10/20 14:04:31 wiz Exp $

BUILDLINK_TREE+=	brasero

.if !defined(BRASERO_BUILDLINK3_MK)
BRASERO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brasero+=	brasero>=3.12.2
BUILDLINK_ABI_DEPENDS.brasero?=	brasero>=3.12.2nb25
BUILDLINK_PKGSRCDIR.brasero?=	../../sysutils/brasero

.include "../../x11/gtk3/buildlink3.mk"
.endif	# BRASERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-brasero
