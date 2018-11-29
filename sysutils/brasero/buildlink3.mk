# $NetBSD: buildlink3.mk,v 1.57 2018/11/29 11:21:46 prlw1 Exp $

BUILDLINK_TREE+=	brasero

.if !defined(BRASERO_BUILDLINK3_MK)
BRASERO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brasero+=	brasero>=2.26.0
BUILDLINK_ABI_DEPENDS.brasero+=	brasero>=2.32.1nb50
BUILDLINK_PKGSRCDIR.brasero?=	../../sysutils/brasero

.include "../../x11/gtk2/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"

.endif # BRASERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-brasero
