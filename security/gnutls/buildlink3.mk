# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 00:21:28 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNUTLS_BUILDLINK3_MK:=	${GNUTLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnutls
.endif

.if !empty(GNUTLS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gnutls
BUILDLINK_DEPENDS.gnutls?=	gnutls>=1.0.1
BUILDLINK_PKGSRCDIR.gnutls?=	../../security/gnutls

.  include "../../archivers/liblzo/buildlink3.mk"
.  include "../../devel/gettext-lib/buildlink3.mk"
.  include "../../devel/zlib/buildlink3.mk"
.  include "../../security/libgcrypt/buildlink3.mk"
.  include "../../security/libtasn1/buildlink3.mk"
.  include "../../security/opencdk/buildlink3.mk"
.endif # GNUTLS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
