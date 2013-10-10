# $NetBSD: buildlink3.mk,v 1.22 2013/10/10 14:41:50 ryoon Exp $

BUILDLINK_TREE+=	libgpod

.if !defined(LIBGPOD_BUILDLINK3_MK)
LIBGPOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.3.2
BUILDLINK_ABI_DEPENDS.libgpod+=	libgpod>=0.8.2nb16
BUILDLINK_PKGSRCDIR.libgpod?=	../../audio/libgpod

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGPOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgpod
