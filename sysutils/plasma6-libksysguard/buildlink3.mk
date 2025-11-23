# $NetBSD: buildlink3.mk,v 1.1 2025/11/23 20:03:56 markd Exp $

BUILDLINK_TREE+=	plasma6-libksysguard

.if !defined(PLASMA6_LIBKSYSGUARD_BUILDLINK3_MK)
PLASMA6_LIBKSYSGUARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-libksysguard+=	plasma6-libksysguard>=6.5.2
BUILDLINK_PKGSRCDIR.plasma6-libksysguard?=	../../sysutils/plasma6-libksysguard

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_LIBKSYSGUARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-libksysguard
