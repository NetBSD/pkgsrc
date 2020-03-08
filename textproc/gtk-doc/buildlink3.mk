# $NetBSD: buildlink3.mk,v 1.9 2020/03/08 16:48:14 wiz Exp $
#
# provided mostly for pkg-config

BUILDLINK_TREE+=	gtk-doc

.if !defined(GTK_DOC_BUILDLINK3_MK)
GTK_DOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.18
BUILDLINK_ABI_DEPENDS.gtk-doc?=	gtk-doc>=1.32nb2
BUILDLINK_PKGSRCDIR.gtk-doc?=	../../textproc/gtk-doc
# needed together with pkg-config by gtkdoc-depscan at runtime
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPMETHOD.gtk-doc?=	build
.endif # GTK_DOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-doc
