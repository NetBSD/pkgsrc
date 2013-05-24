# $NetBSD: buildlink3.mk,v 1.26 2013/05/24 18:23:34 wiz Exp $

BUILDLINK_TREE+=	brasero

.if !defined(BRASERO_BUILDLINK3_MK)
BRASERO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brasero+=	brasero>=2.26.0
BUILDLINK_ABI_DEPENDS.brasero+=	brasero>=2.32.1nb18
BUILDLINK_PKGSRCDIR.brasero?=	../../sysutils/brasero

.include "../../x11/gtk2/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"

.endif # BRASERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-brasero
