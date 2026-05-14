# $NetBSD: buildlink3.mk,v 1.78 2026/05/14 16:41:46 ryoon Exp $

BUILDLINK_TREE+=	libktorrent

.if !defined(LIBKTORRENT_BUILDLINK3_MK)
LIBKTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libktorrent+=	libktorrent>=25.08.2
BUILDLINK_ABI_DEPENDS.libktorrent?=	libktorrent>=25.08.3nb4
BUILDLINK_PKGSRCDIR.libktorrent?=	../../net/libktorrent

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libktorrent
