# $NetBSD: buildlink3.mk,v 1.5 2016/03/22 23:04:15 khorben Exp $

BUILDLINK_TREE+=	cups

.if !defined(CUPS_BUILDLINK3_MK)
CUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cups+=	cups>=1.1.19nb3<1.7
BUILDLINK_ABI_DEPENDS.cups+=	cups>=1.5.4nb15
BUILDLINK_PKGSRCDIR.cups?=	../../print/cups15

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
.include "../../mk/curses.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # CUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cups
