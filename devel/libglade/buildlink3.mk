# $NetBSD: buildlink3.mk,v 1.45 2018/11/14 22:21:16 kleink Exp $

BUILDLINK_TREE+=	libglade

.if !defined(LIBGLADE_BUILDLINK3_MK)
LIBGLADE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.3.6
BUILDLINK_ABI_DEPENDS.libglade+=	libglade>=2.6.4nb29
BUILDLINK_PKGSRCDIR.libglade?=		../../devel/libglade

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGLADE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglade
