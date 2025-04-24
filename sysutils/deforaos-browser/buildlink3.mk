# $NetBSD: buildlink3.mk,v 1.36 2025/04/24 14:15:44 wiz Exp $

BUILDLINK_TREE+=	deforaos-browser

.if !defined(DEFORAOS_BROWSER_BUILDLINK3_MK)
DEFORAOS_BROWSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-browser+=	deforaos-browser>=0.5.0
BUILDLINK_ABI_DEPENDS.deforaos-browser?=	deforaos-browser>=0.5.5nb13
BUILDLINK_PKGSRCDIR.deforaos-browser?=		../../sysutils/deforaos-browser

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_BROWSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-browser
