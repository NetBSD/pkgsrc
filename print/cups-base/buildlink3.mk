# $NetBSD: buildlink3.mk,v 1.30 2024/05/16 06:15:27 wiz Exp $

BUILDLINK_TREE+=	cups-base

.if !defined(CUPS_BASE_BUILDLINK3_MK)
CUPS_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cups-base+=	cups-base>=1.1.19nb3
BUILDLINK_ABI_DEPENDS.cups-base+=	cups-base>=2.4.6nb4
BUILDLINK_PKGSRCDIR.cups-base?=		../../print/cups-base

pkgbase := cups-base
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.cups-base:Mkerberos}
.include "../../mk/krb5.buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.cups-base:Mdnssd}
.include "../../net/mDNSResponder/buildlink3.mk"
.endif

.if ${OPSYS} != "Darwin" && ${PKG_BUILD_OPTIONS.cups-base:Mavahi}
.include "../../net/avahi/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif # CUPS_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cups-base
