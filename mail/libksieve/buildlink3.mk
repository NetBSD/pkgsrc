# $NetBSD: buildlink3.mk,v 1.19 2026/05/14 16:41:24 ryoon Exp $

BUILDLINK_TREE+=	libksieve

.if !defined(LIBKSIEVE_BUILDLINK3_MK)
LIBKSIEVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksieve+=	libksieve>=25.08.3
BUILDLINK_ABI_DEPENDS.libksieve?=	libksieve>=25.08.3nb4
BUILDLINK_PKGSRCDIR.libksieve?=		../../mail/libksieve

.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKSIEVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksieve
