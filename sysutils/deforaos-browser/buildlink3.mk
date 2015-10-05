# $NetBSD: buildlink3.mk,v 1.11 2015/10/05 23:43:55 khorben Exp $

BUILDLINK_TREE+=	deforaos-browser

.if !defined(DEFORAOS_BROWSER_BUILDLINK3_MK)
DEFORAOS_BROWSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-browser+=	deforaos-browser>=0.4.14
BUILDLINK_ABI_DEPENDS.deforaos-browser?=	deforaos-browser>=0.4.14
BUILDLINK_PKGSRCDIR.deforaos-browser?=	../../sysutils/deforaos-browser

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_BROWSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-browser
