# $NetBSD: buildlink3.mk,v 1.19 2004/10/03 00:18:09 tv Exp $

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
BUILDLINK_RECOMMENDED.heimdal+=	heimdal>=0.6.3nb1
BUILDLINK_PKGSRCDIR.heimdal?=	../../security/heimdal
BUILDLINK_INCDIRS.heimdal?=	include/krb5
.endif	# HEIMDAL_BUILDLINK3_MK

PKG_OPTIONS.heimdal?=	${PKG_DEFAULT_OPTIONS}

.include "../../security/openssl/buildlink3.mk"
.if !empty(PKG_OPTIONS.heimdal:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
.else
.  include "../../mk/bdb.buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
