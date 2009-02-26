# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/02/26 10:07:49 hasso Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENCT_BUILDLINK3_MK:=	${OPENCT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openct
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenct}
BUILDLINK_PACKAGES+=	openct
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}openct

.if !empty(OPENCT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.openct+=	openct>=0.6.15
BUILDLINK_PKGSRCDIR.openct?=	../../security/openct
pkgbase := openct
.include "../../mk/pkg-build-options.mk"
.endif	# OPENCT_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.openct:Mpcsc-lite)
.include "../../security/pcsc-lite/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.openct:Mlibusb)
.include "../../devel/libusb/buildlink3.mk"
.endif

.include "../../devel/libltdl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
