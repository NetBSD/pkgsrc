# $NetBSD: buildlink3.mk,v 1.14 2009/02/12 20:55:07 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
POPPLER_BUILDLINK3_MK:=	${POPPLER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	poppler
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npoppler}
BUILDLINK_PACKAGES+=	poppler
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}poppler

.if !empty(POPPLER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.5.1
BUILDLINK_ABI_DEPENDS.poppler+=	poppler>=0.10.0
BUILDLINK_PKGSRCDIR.poppler?=	../../print/poppler

PRINT_PLIST_AWK+=	/^@exec ..MKDIR. %D\/include\/poppler$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm include\/poppler$$/ \
				{ print "@comment in poppler: " $$0; next; }
.endif	# POPPLER_BUILDLINK3_MK

pkgbase := poppler
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.poppler:Mpoppler-cms)
.include "../../graphics/lcms/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
