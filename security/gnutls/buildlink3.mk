# $NetBSD: buildlink3.mk,v 1.35 2019/07/20 22:46:04 wiz Exp $

BUILDLINK_TREE+=	gnutls

.if !defined(GNUTLS_BUILDLINK3_MK)
GNUTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.3.0
BUILDLINK_ABI_DEPENDS.gnutls+=	gnutls>=3.6.8nb1
BUILDLINK_PKGSRCDIR.gnutls?=	../../security/gnutls

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
BUILDLINK_API_DEPENDS.nettle+=		nettle>=3.4.1
.include "../../security/nettle/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.endif # GNUTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnutls
