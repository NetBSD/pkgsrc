# $NetBSD: buildlink3.mk,v 1.21 2020/11/05 09:07:10 ryoon Exp $

BUILDLINK_TREE+=	libxml2

.if !defined(LIBXML2_BUILDLINK3_MK)
LIBXML2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.2
BUILDLINK_ABI_DEPENDS.libxml2+=	libxml2>=2.9.10nb3
BUILDLINK_PKGSRCDIR.libxml2?=	../../textproc/libxml2

BUILDLINK_FILES.libxml2+=	bin/xml2-config

USE_FEATURES+=		glob

pkgbase := libxml2
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.libxml2:Micu}
.include "../../textproc/icu/buildlink3.mk"
.endif

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # LIBXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxml2
