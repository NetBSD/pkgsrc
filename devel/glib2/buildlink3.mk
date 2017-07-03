# $NetBSD: buildlink3.mk,v 1.26 2017/07/03 17:42:45 prlw1 Exp $

BUILDLINK_TREE+=	glib2

.if !defined(GLIB2_BUILDLINK3_MK)
GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
BUILDLINK_ABI_DEPENDS.glib2+=	glib2>=2.34.0
BUILDLINK_PKGSRCDIR.glib2?=	../../devel/glib2

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
