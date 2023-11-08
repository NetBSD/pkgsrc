# $NetBSD: buildlink3.mk,v 1.61 2023/11/08 13:20:30 wiz Exp $

BUILDLINK_TREE+=	libktorrent

.if !defined(LIBKTORRENT_BUILDLINK3_MK)
LIBKTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libktorrent+=	libktorrent>=23.04.3
BUILDLINK_ABI_DEPENDS.libktorrent?=	libktorrent>=23.04.3nb2
BUILDLINK_PKGSRCDIR.libktorrent?=	../../net/libktorrent

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libktorrent
