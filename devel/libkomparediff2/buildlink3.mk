# $NetBSD: buildlink3.mk,v 1.30 2024/01/30 14:21:42 ryoon Exp $

BUILDLINK_TREE+=	libkomparediff2

.if !defined(LIBKOMPAREDIFF2_BUILDLINK3_MK)
LIBKOMPAREDIFF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkomparediff2+=	libkomparediff2>=19.08.3
BUILDLINK_ABI_DEPENDS.libkomparediff2?=	libkomparediff2>=23.04.3nb4
BUILDLINK_PKGSRCDIR.libkomparediff2?=	../../devel/libkomparediff2

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKOMPAREDIFF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkomparediff2
