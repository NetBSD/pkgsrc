# $NetBSD: buildlink3.mk,v 1.5 2005/03/24 05:08:41 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDEPIM_BUILDLINK3_MK:=	${KDEPIM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdepim
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdepim}
BUILDLINK_PACKAGES+=	kdepim

.if !empty(KDEPIM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdepim+=	kdepim>=3.2.2
BUILDLINK_RECOMMENDED.kdepim+=	kdepim>=3.4.0
BUILDLINK_PKGSRCDIR.kdepim?=	../../misc/kdepim3
.endif	# KDEPIM_BUILDLINK3_MK

PKG_OPTIONS.kdepim?=	${PKG_DEFAULT_OPTIONS}

.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.if !empty(PKG_OPTIONS.kdepim:Msasl2)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
