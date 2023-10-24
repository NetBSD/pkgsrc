# $NetBSD: buildlink3.mk,v 1.2 2023/10/24 22:11:09 wiz Exp $

BUILDLINK_TREE+=	libksysguard

.if !defined(LIBKSYSGUARD_BUILDLINK3_MK)
LIBKSYSGUARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libksysguard+=	libksysguard>=5.6.3
BUILDLINK_ABI_DEPENDS.libksysguard?=	libksysguard>=5.24.6nb1
BUILDLINK_PKGSRCDIR.libksysguard?=	../../sysutils/libksysguard

.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
#.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.endif	# LIBKSYSGUARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libksysguard
