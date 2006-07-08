# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:35 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BMP_BUILDLINK3_MK:=	${BMP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	bmp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nbmp}
BUILDLINK_PACKAGES+=	bmp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}bmp

.if !empty(BMP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.bmp+=	bmp>=0.9.7rc2nb3
BUILDLINK_ABI_DEPENDS.bmp?=	bmp>=0.9.7nb5
BUILDLINK_PKGSRCDIR.bmp?=	../../audio/bmp

PRINT_PLIST_AWK+=	/^@dirrm lib\/bmp\/Input$$/ \
			{ print "@comment in bmp: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/bmp\/Output$$/ \
			{ print "@comment in bmp: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/bmp\/Visualization$$/ \
			{ print "@comment in bmp: " $$0; next; }
.endif	# BMP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
