# $NetBSD: buildlink3.mk,v 1.7 2004/10/03 00:18:08 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNUTLS_BUILDLINK3_MK:=	${GNUTLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnutls
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnutls}
BUILDLINK_PACKAGES+=	gnutls

.if !empty(GNUTLS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnutls+=	gnutls>=1.0.13
BUILDLINK_RECOMMENDED.gnutls+=	gnutls>=1.0.20nb2
BUILDLINK_PKGSRCDIR.gnutls?=	../../security/gnutls
.endif	# GNUTLS_BUILDLINK3_MK

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/opencdk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
