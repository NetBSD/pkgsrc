# $NetBSD: buildlink3.mk,v 1.16 2012/12/10 12:06:50 ryoon Exp $

BUILDLINK_TREE+=	sane-backends

.if !defined(SANE_BACKENDS_BUILDLINK3_MK)
SANE_BACKENDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sane-backends+=	sane-backends>=1.0.3
BUILDLINK_ABI_DEPENDS.sane-backends+=	sane-backends>=1.0.23
BUILDLINK_PKGSRCDIR.sane-backends?=	../../graphics/sane-backends

.include "../../mk/bsd.fast.prefs.mk"

.if (${OPSYS} != "SunOS")
. include "../../devel/libusb/buildlink3.mk"
.endif
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # SANE_BACKENDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sane-backends
