# $NetBSD: buildlink3.mk,v 1.27 2017/10/15 23:19:11 prlw1 Exp $

BUILDLINK_TREE+=	glib2

.if !defined(GLIB2_BUILDLINK3_MK)
GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
BUILDLINK_ABI_DEPENDS.glib2+=	glib2>=2.34.0
BUILDLINK_PKGSRCDIR.glib2?=	../../devel/glib2

TOOL_DEPENDS+=	glib2-tools-[0-9]*:../../devel/glib2-tools

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.if empty(MACHINE_PLATFORM:MIRIX-5*)
.include "../../mk/pthread.buildlink3.mk"
.endif
.endif # GLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-glib2
