# $NetBSD: buildlink3.mk,v 1.39 2026/11/11 11:55:57 wiz Exp $

BUILDLINK_TREE+=	libxml2

.if !defined(LIBXML2_BUILDLINK3_MK)
LIBXML2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.2
BUILDLINK_ABI_DEPENDS.libxml2+=	libxml2>=2.15.4nb1
BUILDLINK_INCDIRS.libxml2?=	include/libxml2
BUILDLINK_PKGSRCDIR.libxml2?=	../../textproc/libxml2

BUILDLINK_FILES.libxml2+=	bin/xml2-config

USE_FEATURES+=		glob

pkgbase := libxml2
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.libxml2:Micu}
.include "../../textproc/icu/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # LIBXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxml2
