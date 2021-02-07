# $NetBSD: buildlink3.mk,v 1.28 2021/02/07 06:30:08 ryoon Exp $

BUILDLINK_TREE+=	kdegraphics-mobipocket

.if !defined(KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK)
KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegraphics-mobipocket+=	kdegraphics-mobipocket>=17.12.1
BUILDLINK_ABI_DEPENDS.kdegraphics-mobipocket?=	kdegraphics-mobipocket>=20.04.1nb6
BUILDLINK_PKGSRCDIR.kdegraphics-mobipocket?=	../../graphics/kdegraphics-mobipocket

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDEGRAPHICS_MOBIPOCKET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegraphics-mobipocket
