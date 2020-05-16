# $NetBSD: buildlink3.mk,v 1.1 2020/05/16 18:07:56 maya Exp $

BUILDLINK_TREE+=	libcups

.if !defined(LIBCUPS_BUILDLINK3_MK)
LIBCUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcups+=	libcups>=1.1.19nb3
BUILDLINK_ABI_DEPENDS.libcups+=	libcups>=2.3.1nb3
BUILDLINK_PKGSRCDIR.libcups?=		../../print/libcups

pkgbase := libcups
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libcups:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libcups:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
.endif

.if ${OPSYS} != "Darwin" && !empty(PKG_BUILD_OPTIONS.libcups:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif # LIBCUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcups
