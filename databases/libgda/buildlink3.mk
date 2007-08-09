# $NetBSD: buildlink3.mk,v 1.16 2007/08/09 19:07:38 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGDA_BUILDLINK3_MK:=	${LIBGDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgda
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgda}
BUILDLINK_PACKAGES+=	libgda
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgda

.if !empty(LIBGDA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgda+=	libgda>=2.99.2
BUILDLINK_ABI_DEPENDS.libgda+=	libgda>=3.0.0
BUILDLINK_PKGSRCDIR.libgda?=	../../databases/libgda

PRINT_PLIST_AWK+=	/^@dirrm lib\/libgda-3.0\/providers$$/ \
				{ print "@comment in libgda: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/libgda-3.0$$/ \
				{ print "@comment in libgda: " $$0; next; }
.endif	# LIBGDA_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := libgda
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libgda:Mfam)
.include "../../mk/fam.buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
