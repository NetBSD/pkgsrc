# $NetBSD: buildlink3.mk,v 1.69 2023/01/29 21:14:58 ryoon Exp $

BUILDLINK_TREE+=	brasero

.if !defined(BRASERO_BUILDLINK3_MK)
BRASERO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brasero+=	brasero>=3.12.2
BUILDLINK_ABI_DEPENDS.brasero?=	brasero>=3.12.2nb16
BUILDLINK_PKGSRCDIR.brasero?=	../../sysutils/brasero

.include "../../x11/gtk3/buildlink3.mk"
.endif	# BRASERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-brasero
