# $NetBSD: buildlink3.mk,v 1.5 2004/05/06 11:15:31 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGDA_BUILDLINK3_MK:=	${LIBGDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgda
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgda}
BUILDLINK_PACKAGES+=	libgda

.if !empty(LIBGDA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgda+=	libgda>=1.0.3
BUILDLINK_PKGSRCDIR.libgda?=	../../databases/libgda

PRINT_PLIST_AWK+=	/^@dirrm lib\/libgda\/providers$$/ \
				{ print "@comment in libgda: " $$0; next; }
.endif	# LIBGDA_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
