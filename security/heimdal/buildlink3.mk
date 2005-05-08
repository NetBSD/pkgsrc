# $NetBSD: buildlink3.mk,v 1.21 2005/05/08 12:03:56 jlam Exp $

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

.if !defined(PKG_OPTIONS.heimdal)
PKG_OPTIONS.heimdal!=							\
	cd ${BUILDLINK_PKGSRCDIR.heimdal} &&				\
	${MAKE} show-var ${MAKE_FLAGS} VARNAME=PKG_OPTIONS
MAKE_FLAGS+=			PKG_OPTIONS.heimdal=${PKG_OPTIONS.heimdal:Q}
WRAPPER_VARS+=			PKG_OPTIONS.heimdal
.endif

.include "../../security/openssl/buildlink3.mk"
.if !empty(PKG_OPTIONS.heimdal:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
.else
.  include "../../mk/bdb.buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
