# $NetBSD: buildlink3.mk,v 1.19 2016/04/09 14:19:25 richard Exp $

BUILDLINK_TREE+=	sane-backends

.if !defined(SANE_BACKENDS_BUILDLINK3_MK)
SANE_BACKENDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sane-backends+=	sane-backends>=1.0.3
BUILDLINK_ABI_DEPENDS.sane-backends+=	sane-backends>=1.0.24
BUILDLINK_PKGSRCDIR.sane-backends?=	../../graphics/sane-backends

.include "../../mk/bsd.fast.prefs.mk"

. include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # SANE_BACKENDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sane-backends
