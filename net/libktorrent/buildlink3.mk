# $NetBSD: buildlink3.mk,v 1.74 2025/12/21 15:09:54 markd Exp $

BUILDLINK_TREE+=	libktorrent

.if !defined(LIBKTORRENT_BUILDLINK3_MK)
LIBKTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libktorrent+=	libktorrent>=25.08.2
BUILDLINK_ABI_DEPENDS.libktorrent?=	libktorrent>=25.08.2
BUILDLINK_PKGSRCDIR.libktorrent?=	../../net/libktorrent

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libktorrent
