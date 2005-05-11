# $NetBSD: buildlink3.mk,v 1.24 2005/05/11 22:03:52 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HEIMDAL_BUILDLINK3_MK:=	${HEIMDAL_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	heimdal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nheimdal}
BUILDLINK_PACKAGES+=	heimdal

.if !empty(HEIMDAL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.heimdal+=	heimdal>=0.4e
BUILDLINK_RECOMMENDED.heimdal+=	heimdal>=0.6.3nb2
BUILDLINK_PKGSRCDIR.heimdal?=	../../security/heimdal
BUILDLINK_INCDIRS.heimdal?=	include/krb5
.endif	# HEIMDAL_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.heimdal)
PKG_BUILD_OPTIONS.heimdal!=						\
	cd ${BUILDLINK_PKGSRCDIR.heimdal} &&				\
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.heimdal=${PKG_BUILD_OPTIONS.heimdal:Q}
.endif
MAKE_VARS+=	PKG_BUILD_OPTIONS.heimdal

.include "../../security/openssl/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.heimdal:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
.else
.  include "../../mk/bdb.buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
