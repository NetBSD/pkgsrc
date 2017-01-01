# $NetBSD: buildlink3.mk,v 1.7 2017/01/01 16:05:58 adam Exp $

BUILDLINK_TREE+=	kdegraphics-mobipocket

.if !defined(KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK)
KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegraphics-mobipocket+=	kdegraphics-mobipocket>=4.14.3
BUILDLINK_ABI_DEPENDS.kdegraphics-mobipocket?=	kdegraphics-mobipocket>=15.12.0nb3
BUILDLINK_PKGSRCDIR.kdegraphics-mobipocket?=	../../graphics/kdegraphics-mobipocket

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegraphics-mobipocket
