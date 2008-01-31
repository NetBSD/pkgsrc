# $NetBSD: buildlink3.mk,v 1.20 2008/01/31 01:04:26 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNUTLS_BUILDLINK3_MK:=	${GNUTLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnutls
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnutls}
BUILDLINK_PACKAGES+=	gnutls
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnutls

.if !empty(GNUTLS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=1.2.6
BUILDLINK_ABI_DEPENDS.gnutls+=	gnutls>=1.6.3nb1
BUILDLINK_PKGSRCDIR.gnutls?=	../../security/gnutls
.endif	# GNUTLS_BUILDLINK3_MK

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/opencdk/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
