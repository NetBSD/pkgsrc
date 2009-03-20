# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:23:52 joerg Exp $

BUILDLINK_TREE+=	bmp

.if !defined(BMP_BUILDLINK3_MK)
BMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bmp+=	bmp>=0.9.7rc2nb3
BUILDLINK_ABI_DEPENDS.bmp?=	bmp>=0.9.7nb5
BUILDLINK_PKGSRCDIR.bmp?=	../../audio/bmp

PRINT_PLIST_AWK+=	/^@dirrm lib\/bmp\/Input$$/ \
			{ print "@comment in bmp: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/bmp\/Output$$/ \
			{ print "@comment in bmp: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/bmp\/Visualization$$/ \
			{ print "@comment in bmp: " $$0; next; }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # BMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-bmp
