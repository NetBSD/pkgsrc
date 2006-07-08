# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 22:39:04 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGDA_BUILDLINK3_MK:=	${LIBGDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgda
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgda}
BUILDLINK_PACKAGES+=	libgda
BUILDLINK_ORDER+=	libgda

.if !empty(LIBGDA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgda+=	libgda>=1.9.100
BUILDLINK_ABI_DEPENDS.libgda?=	libgda>=1.9.100nb1
BUILDLINK_PKGSRCDIR.libgda?=	../../databases/libgda

PRINT_PLIST_AWK+=	/^@dirrm lib\/libgda-1.9\/providers$$/ \
				{ print "@comment in libgda: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/libgda$$/ \
				{ print "@comment in libgda: " $$0; next; }
.endif	# LIBGDA_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
