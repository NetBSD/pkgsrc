# $NetBSD: buildlink3.mk,v 1.6 2013/09/02 19:50:45 adam Exp $
#

BUILDLINK_TREE+=	deforaos-browser

.if !defined(DEFORAOS_BROWSER_BUILDLINK3_MK)
DEFORAOS_BROWSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-browser+=	deforaos-browser>=0.4.5
BUILDLINK_ABI_DEPENDS.deforaos-browser?=	deforaos-browser>=0.4.12nb2
BUILDLINK_PKGSRCDIR.deforaos-browser?=	../../sysutils/deforaos-browser

.include "../../x11/gtk2/buildlink3.mk"
.endif	# DEFORAOS_BROWSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-browser
