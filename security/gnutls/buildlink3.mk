# $NetBSD: buildlink3.mk,v 1.23 2010/09/01 16:32:17 drochner Exp $

BUILDLINK_TREE+=	gnutls

.if !defined(GNUTLS_BUILDLINK3_MK)
GNUTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=1.2.6
BUILDLINK_ABI_DEPENDS.gnutls+=	gnutls>=2.2.2
BUILDLINK_PKGSRCDIR.gnutls?=	../../security/gnutls

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.endif # GNUTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnutls
