# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:24:18 joerg Exp $

BUILDLINK_TREE+=	libglade

.if !defined(LIBGLADE_BUILDLINK3_MK)
LIBGLADE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.3.6
BUILDLINK_ABI_DEPENDS.libglade+=	libglade>=2.5.1nb4
BUILDLINK_PKGSRCDIR.libglade?=	../../devel/libglade

PRINT_PLIST_AWK+=	/^@dirrm lib\/libglade$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/libglade\/2.0$$/ \
				{ print "@comment in libglade: " $$0; next; }

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGLADE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglade
