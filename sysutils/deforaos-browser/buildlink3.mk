# $NetBSD: buildlink3.mk,v 1.2 2013/02/16 11:18:29 wiz Exp $
#

BUILDLINK_TREE+=	deforaos-browser

.if !defined(DEFORAOS_BROWSER_BUILDLINK3_MK)
DEFORAOS_BROWSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-browser+=	deforaos-browser>=0.4.5
BUILDLINK_ABI_DEPENDS.deforaos-browser?=	deforaos-browser>=0.4.9nb1
BUILDLINK_PKGSRCDIR.deforaos-browser?=	../../sysutils/deforaos-browser

.include "../../x11/gtk2/buildlink3.mk"
.endif	# DEFORAOS_BROWSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-browser
