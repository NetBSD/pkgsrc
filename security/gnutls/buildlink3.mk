# $NetBSD: buildlink3.mk,v 1.27 2011/07/11 16:10:29 drochner Exp $

BUILDLINK_TREE+=	gnutls

.if !defined(GNUTLS_BUILDLINK3_MK)
GNUTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=2.12.3
BUILDLINK_ABI_DEPENDS.gnutls+=	gnutls>=2.12.3
BUILDLINK_PKGSRCDIR.gnutls?=	../../security/gnutls

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.endif # GNUTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnutls
