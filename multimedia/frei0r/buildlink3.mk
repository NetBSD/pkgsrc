# $NetBSD: buildlink3.mk,v 1.8 2026/01/27 08:40:15 wiz Exp $

BUILDLINK_TREE+=	frei0r

.if !defined(FREI0R_BUILDLINK3_MK)
FREI0R_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.frei0r+=	frei0r>=1.6.1
BUILDLINK_ABI_DEPENDS.frei0r?=	frei0r>=2.3.3nb6
BUILDLINK_PKGSRCDIR.frei0r?=	../../multimedia/frei0r

.include "../../graphics/cairo/buildlink3.mk"
.endif	# FREI0R_BUILDLINK3_MK

BUILDLINK_TREE+=	-frei0r
