# $NetBSD: buildlink3.mk,v 1.48 2026/09/27 11:35:42 tnn Exp $

BUILDLINK_TREE+=	libkomparediff2

.if !defined(LIBKOMPAREDIFF2_BUILDLINK3_MK)
LIBKOMPAREDIFF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkomparediff2+=	libkomparediff2>=25.08.2
BUILDLINK_ABI_DEPENDS.libkomparediff2?=	libkomparediff2>=26.08.0nb1
BUILDLINK_PKGSRCDIR.libkomparediff2?=	../../devel/libkomparediff2

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKOMPAREDIFF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkomparediff2
