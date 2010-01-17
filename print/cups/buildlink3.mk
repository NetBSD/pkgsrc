# $NetBSD: buildlink3.mk,v 1.23 2010/01/17 12:02:37 wiz Exp $

BUILDLINK_TREE+=	cups

.if !defined(CUPS_BUILDLINK3_MK)
CUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cups+=	cups>=1.1.19nb3
BUILDLINK_ABI_DEPENDS.cups+=	cups>=1.3.11nb2
BUILDLINK_PKGSRCDIR.cups?=	../../print/cups

pkgbase := cups
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.cups:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
.endif

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # CUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cups
