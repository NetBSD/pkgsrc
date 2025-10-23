# $NetBSD: buildlink3.mk,v 1.7 2025/10/23 20:38:32 wiz Exp $

BUILDLINK_TREE+=	frei0r

.if !defined(FREI0R_BUILDLINK3_MK)
FREI0R_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.frei0r+=	frei0r>=1.6.1
BUILDLINK_ABI_DEPENDS.frei0r?=	frei0r>=2.3.3nb4
BUILDLINK_PKGSRCDIR.frei0r?=	../../multimedia/frei0r

.include "../../graphics/cairo/buildlink3.mk"
.endif	# FREI0R_BUILDLINK3_MK

BUILDLINK_TREE+=	-frei0r
