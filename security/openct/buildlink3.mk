# $NetBSD: buildlink3.mk,v 1.6 2026/02/03 08:39:32 wiz Exp $

BUILDLINK_TREE+=	openct

.if !defined(OPENCT_BUILDLINK3_MK)
OPENCT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openct+=	openct>=0.6.15
BUILDLINK_ABI_DEPENDS.openct+=	openct>=0.6.18nb2
BUILDLINK_PKGSRCDIR.openct?=	../../security/openct
pkgbase := openct
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.openct:Mpcsc-lite}
.include "../../security/pcsc-lite/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.openct:Mlibusb}
.include "../../mk/libusb.buildlink3.mk"
.endif

.include "../../devel/libltdl/buildlink3.mk"
.endif # OPENCT_BUILDLINK3_MK

BUILDLINK_TREE+=	-openct
