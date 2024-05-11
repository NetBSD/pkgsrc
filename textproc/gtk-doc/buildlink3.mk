# $NetBSD: buildlink3.mk,v 1.13 2024/05/11 18:58:52 adam Exp $
#
# provided mostly for pkg-config

BUILDLINK_TREE+=	gtk-doc

.if !defined(GTK_DOC_BUILDLINK3_MK)
GTK_DOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.18
BUILDLINK_ABI_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb13
BUILDLINK_PKGSRCDIR.gtk-doc?=	../../textproc/gtk-doc
BUILDLINK_DEPMETHOD.gtk-doc?=	build

.endif # GTK_DOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-doc
