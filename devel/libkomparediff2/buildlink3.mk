# $NetBSD: buildlink3.mk,v 1.44 2026/05/14 16:40:45 ryoon Exp $

BUILDLINK_TREE+=	libkomparediff2

.if !defined(LIBKOMPAREDIFF2_BUILDLINK3_MK)
LIBKOMPAREDIFF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkomparediff2+=	libkomparediff2>=25.08.2
BUILDLINK_ABI_DEPENDS.libkomparediff2?=	libkomparediff2>=25.08.3nb4
BUILDLINK_PKGSRCDIR.libkomparediff2?=	../../devel/libkomparediff2

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKOMPAREDIFF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkomparediff2
