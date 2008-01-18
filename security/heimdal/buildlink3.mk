# $NetBSD: buildlink3.mk,v 1.33 2008/01/18 05:09:37 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HEIMDAL_BUILDLINK3_MK:=	${HEIMDAL_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	heimdal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nheimdal}
BUILDLINK_PACKAGES+=	heimdal
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}heimdal

.if !empty(HEIMDAL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.heimdal+=	heimdal>=0.4e
BUILDLINK_ABI_DEPENDS.heimdal+=	heimdal>=0.7.2nb4
BUILDLINK_PKGSRCDIR.heimdal?=	../../security/heimdal
BUILDLINK_INCDIRS.heimdal?=	include/krb5
.endif	# HEIMDAL_BUILDLINK3_MK

pkgbase := heimdal
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.heimdal:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
