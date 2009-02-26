# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/02/26 10:50:05 hasso Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENSC_BUILDLINK3_MK:=	${OPENSC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opensc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopensc}
BUILDLINK_PACKAGES+=	opensc
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}opensc

.if !empty(OPENSC_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.opensc+=	opensc>=0.11.5
BUILDLINK_PKGSRCDIR.opensc?=	../../security/opensc
pkgbase := opensc
.include "../../mk/pkg-build-options.mk"
.endif	# OPENSC_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.opensc:Mopenct)
.include "../../security/openct/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
