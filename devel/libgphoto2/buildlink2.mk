# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/12/24 16:18:15 wiz Exp $
#

.if !defined(LIBGPHOTO2_BUILDLINK2_MK)
LIBGPHOTO2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgphoto2
BUILDLINK_DEPENDS.libgphoto2?=		libgphoto2>=2.1.1
BUILDLINK_PKGSRCDIR.libgphoto2?=	../../devel/libgphoto2

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgphoto2=libgphoto2
BUILDLINK_PREFIX.libgphoto2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgphoto2+=	include/gphoto2/*.h
BUILDLINK_FILES.libgphoto2+=	lib/gphoto2/*/*
BUILDLINK_FILES.libgphoto2+=	lib/libgphoto2.*
BUILDLINK_FILES.libgphoto2+=	lib/libgphoto2_port.*

.include "../../devel/gettext-lib/buildlink2.mk"
#.include "../../devel/libusb/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"

BUILDLINK_TARGETS+=	libgphoto2-buildlink

libgphoto2-buildlink: _BUILDLINK_USE

.endif	# LIBGPHOTO2_BUILDLINK2_MK
