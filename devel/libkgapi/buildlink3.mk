# $NetBSD: buildlink3.mk,v 1.7 2023/11/12 13:21:06 wiz Exp $

BUILDLINK_TREE+=	libkgapi

.if !defined(LIBKGAPI_BUILDLINK3_MK)
LIBKGAPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkgapi+=	libkgapi>=20.04.1
BUILDLINK_ABI_DEPENDS.libkgapi?=		libkgapi>=23.04.3nb3
BUILDLINK_PKGSRCDIR.libkgapi?=		../../devel/libkgapi

.include "../../devel/kio/buildlink3.mk"
.include "../../misc/kcontacts/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../time/kcalendarcore/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKGAPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkgapi
