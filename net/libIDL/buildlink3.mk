# $NetBSD: buildlink3.mk,v 1.20 2026/09/02 19:03:59 wiz Exp $

BUILDLINK_TREE+=	libIDL

.if !defined(LIBIDL_BUILDLINK3_MK)
LIBIDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libIDL+=	libIDL>=0.8.3nb1
BUILDLINK_ABI_DEPENDS.libIDL+=	libIDL>=0.8.14nb8
BUILDLINK_PKGSRCDIR.libIDL?=	../../net/libIDL

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBIDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libIDL
