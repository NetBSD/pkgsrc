# $NetBSD: buildlink3.mk,v 1.23 2008/01/18 05:08:36 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDEPIM_BUILDLINK3_MK:=	${KDEPIM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdepim
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdepim}
BUILDLINK_PACKAGES+=	kdepim
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdepim

.if !empty(KDEPIM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.kdepim+=	kdepim>=3.5.0nb1
BUILDLINK_ABI_DEPENDS.kdepim?=	kdepim>=3.5.8nb2
BUILDLINK_PKGSRCDIR.kdepim?=	../../misc/kdepim3
.endif	# KDEPIM_BUILDLINK3_MK

pkgbase := kdepim
.include "../../mk/pkg-build-options.mk"

.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.kdepim:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
