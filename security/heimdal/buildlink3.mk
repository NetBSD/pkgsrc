# $NetBSD: buildlink3.mk,v 1.28 2006/05/31 18:22:26 ghen Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HEIMDAL_BUILDLINK3_MK:=	${HEIMDAL_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	heimdal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nheimdal}
BUILDLINK_PACKAGES+=	heimdal

.if !empty(HEIMDAL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.heimdal+=	heimdal>=0.4e
BUILDLINK_ABI_DEPENDS.heimdal+=	heimdal>=0.6.3nb2
BUILDLINK_PKGSRCDIR.heimdal?=	../../security/heimdal
BUILDLINK_INCDIRS.heimdal?=	include/krb5
.endif	# HEIMDAL_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.heimdal)
PKG_BUILD_OPTIONS.heimdal!=						\
	cd ${BUILDLINK_PKGSRCDIR.heimdal} &&				\
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.heimdal=${PKG_BUILD_OPTIONS.heimdal:Q}
.endif
MAKEVARS+=	PKG_BUILD_OPTIONS.heimdal

.if !empty(PKG_BUILD_OPTIONS.heimdal:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
