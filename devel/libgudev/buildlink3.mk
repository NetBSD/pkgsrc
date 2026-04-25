# $NetBSD: buildlink3.mk,v 1.5 2026/04/25 10:45:50 vins Exp $

BUILDLINK_TREE+=	libgudev

.if !defined(LIBGUDEV_BUILDLINK3_MK)
LIBGUDEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgudev+=	libgudev>=238
BUILDLINK_ABI_DEPENDS.libgudev?=	libgudev>=238nb3
BUILDLINK_PKGSRCDIR.libgudev?=		../../devel/libgudev

BUILDLINK_INCDIRS.libgudev?=	include/gudev-1.0/gudev

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD}
.  include "../../devel/libudev-bsd/buildlink3.mk"
.elif ${OPSYS} == "Linux"
# udev_device_get_current_tags()
BUILDLINK_API_DEPENDS.libudev+=   libudev>=3.2.14
.  include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../devel/gobject-introspection/buildlink3.mk"
.endif	# LIBGUDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgudev
