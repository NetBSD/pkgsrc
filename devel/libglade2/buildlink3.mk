# $NetBSD: buildlink3.mk,v 1.5 2004/04/20 16:14:03 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADE2_BUILDLINK3_MK:=	${LIBGLADE2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglade2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglade2}
BUILDLINK_PACKAGES+=	libglade2

.if !empty(LIBGLADE2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libglade2+=	libglade2>=2.3.6
BUILDLINK_PKGSRCDIR.libglade2?=	../../devel/libglade2

PRINT_PLIST_AWK+=	/^@dirrm lib\/libglade$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/libglade\/2.0$$/ \
				{ print "@comment in libglade2: " $$0; next; }
.endif	# LIBGLADE2_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
