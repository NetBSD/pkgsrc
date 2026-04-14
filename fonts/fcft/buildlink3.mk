# $NetBSD: buildlink3.mk,v 1.1 2026/04/14 12:06:06 kikadf Exp $

BUILDLINK_TREE+=	fcft

.if !defined(FCFT_BUILDLINK3_MK)
FCFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcft+=	fcft>=3.1.8
BUILDLINK_PKGSRCDIR.fcft?=	../../fonts/fcft

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../devel/tllist/buildlink3.mk"
.endif	# FCFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcft
