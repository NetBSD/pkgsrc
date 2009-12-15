# $NetBSD: buildlink3.mk,v 1.3 2009/12/15 22:10:39 joerg Exp $

BUILDLINK_TREE+=	openct

.if !defined(OPENCT_BUILDLINK3_MK)
OPENCT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openct+=	openct>=0.6.15
BUILDLINK_ABI_DEPENDS.openct+=	openct>=0.6.18nb2
BUILDLINK_PKGSRCDIR.openct?=	../../security/openct
pkgbase := openct
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.openct:Mpcsc-lite)
.include "../../security/pcsc-lite/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.openct:Mlibusb)
.include "../../devel/libusb/buildlink3.mk"
.endif

.include "../../devel/libltdl/buildlink3.mk"
.endif # OPENCT_BUILDLINK3_MK

BUILDLINK_TREE+=	-openct
