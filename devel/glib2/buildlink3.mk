# $NetBSD: buildlink3.mk,v 1.35 2023/08/14 05:24:08 wiz Exp $

BUILDLINK_TREE+=	glib2

.if !defined(GLIB2_BUILDLINK3_MK)
GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
BUILDLINK_ABI_DEPENDS.glib2+=	glib2>=2.76.4nb1
BUILDLINK_PKGSRCDIR.glib2?=	../../devel/glib2
BUILDLINK_INCDIRS.glib2+=	include/glib-2.0
BUILDLINK_INCDIRS.glib2+=	include/gio-unix-2.0
BUILDLINK_INCDIRS.glib2+=	lib/glib-2.0/include

BUILDLINK_FILES.glib2+=		bin/glib-compile-resources
BUILDLINK_FILES.glib2+=		bin/glib-compile-schemas

TOOL_DEPENDS+=	glib2-tools-[0-9]*:../../devel/glib2-tools

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-glib2
