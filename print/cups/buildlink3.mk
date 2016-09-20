# $NetBSD: buildlink3.mk,v 1.36 2016/09/20 11:12:22 wiz Exp $

BUILDLINK_TREE+=	cups

.if !defined(CUPS_BUILDLINK3_MK)
CUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cups+=	cups>=1.1.19nb3
BUILDLINK_ABI_DEPENDS.cups+=	cups>=2.1.4nb2
BUILDLINK_PKGSRCDIR.cups?=	../../print/cups

pkgbase := cups
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.cups:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.cups:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif # CUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cups
