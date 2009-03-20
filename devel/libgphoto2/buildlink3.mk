# $NetBSD: buildlink3.mk,v 1.15 2009/03/20 19:24:19 joerg Exp $

BUILDLINK_TREE+=	libgphoto2

.if !defined(LIBGPHOTO2_BUILDLINK3_MK)
LIBGPHOTO2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgphoto2+=		libgphoto2>=2.1.2
BUILDLINK_ABI_DEPENDS.libgphoto2+=	libgphoto2>=2.1.6nb1
BUILDLINK_PKGSRCDIR.libgphoto2?=	../../devel/libgphoto2

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "SunOS"
.include "../../devel/libusb/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.endif # LIBGPHOTO2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgphoto2
