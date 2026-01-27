# $NetBSD: buildlink3.mk,v 1.17 2026/01/27 08:40:03 wiz Exp $

BUILDLINK_TREE+=	libksieve

.if !defined(LIBKSIEVE_BUILDLINK3_MK)
LIBKSIEVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksieve+=	libksieve>=25.08.3
BUILDLINK_ABI_DEPENDS.libksieve?=	libksieve>=25.08.3nb2
BUILDLINK_PKGSRCDIR.libksieve?=		../../mail/libksieve

.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKSIEVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksieve
