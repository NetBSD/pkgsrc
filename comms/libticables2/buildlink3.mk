# $NetBSD: buildlink3.mk,v 1.1 2013/05/26 22:57:53 rodent Exp $

BUILDLINK_TREE+=	libticables2

.if !defined(LIBTICABLES2_BUILDLINK3_MK)
LIBTICABLES2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticables2+=	libticables2>=1.3.3
BUILDLINK_PKGSRCDIR.libticables2?=	../../comms/libticables2

pkgbase := libticables2
.include "../../mk/pkg-build-options.mk"


.if !empty(PKG_BUILD_OPTIONS.libticables2:Mlibusb)
.if empty(PKG_BUILD_OPTIONS.libticables2:Mlibusb1)
.include "../../devel/libusb/buildlink3.mk"
.endif
.endif

.if !empty(PKG_BUILD_OPTIONS.libticables2:Mlibusb1)
.include "../../devel/libusb1/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBTICABLES2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticables2
