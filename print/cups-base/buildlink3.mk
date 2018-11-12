# $NetBSD: buildlink3.mk,v 1.8 2018/11/12 03:51:21 ryoon Exp $

BUILDLINK_TREE+=	cups-base

.if !defined(CUPS_BASE_BUILDLINK3_MK)
CUPS_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cups-base+=	cups-base>=1.1.19nb3
BUILDLINK_ABI_DEPENDS.cups-base+=	cups-base>=2.2.8nb4
BUILDLINK_PKGSRCDIR.cups-base?=		../../print/cups-base

pkgbase := cups-base
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.cups-base:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.cups-base:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
.endif

.if ${OPSYS} != "Darwin" && !empty(PKG_BUILD_OPTIONS.cups-base:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif # CUPS_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cups-base
