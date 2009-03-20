# $NetBSD: buildlink3.mk,v 1.15 2009/03/20 19:25:15 joerg Exp $

BUILDLINK_TREE+=	poppler

.if !defined(POPPLER_BUILDLINK3_MK)
POPPLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.5.1
BUILDLINK_ABI_DEPENDS.poppler+=	poppler>=0.10.0
BUILDLINK_PKGSRCDIR.poppler?=	../../print/poppler

PRINT_PLIST_AWK+=	/^@exec ..MKDIR. %D\/include\/poppler$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/poppler$$/ \
				{ print "@comment in poppler: " $$0; next; }

pkgbase := poppler
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.poppler:Mpoppler-cms)
.include "../../graphics/lcms/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # POPPLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler
