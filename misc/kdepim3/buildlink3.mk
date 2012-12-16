# $NetBSD: buildlink3.mk,v 1.40 2012/12/16 01:52:24 obache Exp $

BUILDLINK_TREE+=	kdepim

.if !defined(KDEPIM_BUILDLINK3_MK)
KDEPIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdepim+=	kdepim>=3.5.0nb1
BUILDLINK_ABI_DEPENDS.kdepim+=	kdepim>=3.5.10nb20
BUILDLINK_PKGSRCDIR.kdepim?=	../../misc/kdepim3

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
.endif # KDEPIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdepim
