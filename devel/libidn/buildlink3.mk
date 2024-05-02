# $NetBSD: buildlink3.mk,v 1.15 2024/05/02 14:50:49 cheusov Exp $

BUILDLINK_TREE+=	libidn

.if !defined(LIBIDN_BUILDLINK3_MK)
LIBIDN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libidn+=	libidn>=0.4.6
BUILDLINK_ABI_DEPENDS.libidn+=	libidn>=1.38nb1
BUILDLINK_PKGSRCDIR.libidn?=	../../devel/libidn

pkgbase:= libidn
.include "../../mk/pkg-build-options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.libidn:Mnls}
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.include "../../devel/libgetopt/buildlink3.mk"
.endif # LIBIDN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libidn
