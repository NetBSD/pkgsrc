# $NetBSD: buildlink3.mk,v 1.56 2026/01/07 08:47:19 wiz Exp $

BUILDLINK_TREE+=	kdegraphics-mobipocket

.if !defined(KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK)
KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegraphics-mobipocket+=	kdegraphics-mobipocket>=25.08.2
BUILDLINK_ABI_DEPENDS.kdegraphics-mobipocket?=	kdegraphics-mobipocket>=25.08.3nb1
BUILDLINK_PKGSRCDIR.kdegraphics-mobipocket?=	../../graphics/kdegraphics-mobipocket

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegraphics-mobipocket
