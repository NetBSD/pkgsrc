# $NetBSD: buildlink3.mk,v 1.15 2006/07/08 23:10:44 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADE2_BUILDLINK3_MK:=	${LIBGLADE2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglade2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglade2}
BUILDLINK_PACKAGES+=	libglade2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libglade2

.if !empty(LIBGLADE2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libglade2+=	libglade2>=2.3.6
BUILDLINK_ABI_DEPENDS.libglade2+=	libglade2>=2.5.1nb4
BUILDLINK_PKGSRCDIR.libglade2?=	../../devel/libglade2

PRINT_PLIST_AWK+=	/^@dirrm lib\/libglade$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/libglade\/2.0$$/ \
				{ print "@comment in libglade2: " $$0; next; }
.endif	# LIBGLADE2_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
