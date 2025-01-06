# $NetBSD: buildlink3.mk,v 1.21 2025/01/06 21:49:03 ktnb Exp $

BUILDLINK_TREE+=	libslang

.if !defined(LIBSLANG_BUILDLINK3_MK)
LIBSLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libslang+=	libslang>=2.1.3
BUILDLINK_ABI_DEPENDS.libslang+=	libslang>=2.3.3
BUILDLINK_PKGSRCDIR.libslang?=	../../devel/libslang
pkgbase:=	libslang
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libslang:Mpng}
.  include "../../graphics/png/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libslang:Mpcre}
.  include "../../devel/pcre/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libslang:Moniguruma}
.  include "../../textproc/oniguruma/buildlink3.mk"
.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # LIBSLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libslang
