# $NetBSD: buildlink3.mk,v 1.17 2009/03/20 19:24:14 joerg Exp $

BUILDLINK_TREE+=	glib2

.if !defined(GLIB2_BUILDLINK3_MK)
GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
BUILDLINK_ABI_DEPENDS.glib2+=	glib2>=2.14.3
BUILDLINK_PKGSRCDIR.glib2?=	../../devel/glib2

PRINT_PLIST_AWK+=	/^@dirrm lib\/gio$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/gio\/modules$$/ \
				{ print "@comment in glib2: " $$0; next; }

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-glib2
