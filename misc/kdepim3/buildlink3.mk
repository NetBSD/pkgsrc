# $NetBSD: buildlink3.mk,v 1.10 2005/05/11 22:03:52 jlam Exp $

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

.if !defined(PKG_BUILD_OPTIONS.kdepim)
PKG_BUILD_OPTIONS.kdepim!=						\
	cd ${BUILDLINK_PKGSRCDIR.kdepim} &&				\
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.kdepim=${PKG_BUILD_OPTIONS.kdepim:Q}
.endif
MAKE_VARS+=	PKG_BUILD_OPTIONS.kdepim

.include "../../comms/libmal/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.kdepim:Msasl)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
