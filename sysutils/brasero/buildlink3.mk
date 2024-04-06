# $NetBSD: buildlink3.mk,v 1.73 2024/04/06 08:06:40 wiz Exp $

BUILDLINK_TREE+=	brasero

.if !defined(BRASERO_BUILDLINK3_MK)
BRASERO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brasero+=	brasero>=3.12.2
BUILDLINK_ABI_DEPENDS.brasero?=	brasero>=3.12.2nb22
BUILDLINK_PKGSRCDIR.brasero?=	../../sysutils/brasero

.include "../../x11/gtk3/buildlink3.mk"
.endif	# BRASERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-brasero
