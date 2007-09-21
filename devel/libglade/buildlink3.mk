# $NetBSD: buildlink3.mk,v 1.13 2007/09/21 12:58:55 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADE_BUILDLINK3_MK:=	${LIBGLADE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglade
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglade}
BUILDLINK_PACKAGES+=	libglade
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libglade

.if !empty(LIBGLADE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.3.6
BUILDLINK_ABI_DEPENDS.libglade+=	libglade>=2.5.1nb4
BUILDLINK_PKGSRCDIR.libglade?=	../../devel/libglade

PRINT_PLIST_AWK+=	/^@dirrm lib\/libglade$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/libglade\/2.0$$/ \
				{ print "@comment in libglade: " $$0; next; }
.endif	# LIBGLADE_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
