# $NetBSD: buildlink3.mk,v 1.21 2026/02/06 10:04:34 wiz Exp $

BUILDLINK_TREE+=	libkgapi

.if !defined(LIBKGAPI_BUILDLINK3_MK)
LIBKGAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkgapi+=	libkgapi>=25.08.2
BUILDLINK_ABI_DEPENDS.libkgapi?=	libkgapi>=25.08.3nb13
BUILDLINK_PKGSRCDIR.libkgapi?=		../../devel/libkgapi

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../time/kf6-kcalendarcore/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKGAPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkgapi
