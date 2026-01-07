# $NetBSD: buildlink3.mk,v 1.75 2026/01/07 08:48:21 wiz Exp $

BUILDLINK_TREE+=	libktorrent

.if !defined(LIBKTORRENT_BUILDLINK3_MK)
LIBKTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libktorrent+=	libktorrent>=25.08.2
BUILDLINK_ABI_DEPENDS.libktorrent?=	libktorrent>=25.08.3nb1
BUILDLINK_PKGSRCDIR.libktorrent?=	../../net/libktorrent

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libktorrent
