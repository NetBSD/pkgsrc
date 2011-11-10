# $NetBSD: buildlink3.mk,v 1.7 2011/11/10 09:42:48 abs Exp $
#
# provided mostly for pkg-config

BUILDLINK_TREE+=	gtk-doc

.if !defined(GTK_DOC_BUILDLINK3_MK)
GTK_DOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.18
BUILDLINK_PKGSRCDIR.gtk-doc?=	../../textproc/gtk-doc

BUILDLINK_DEPMETHOD.gtk-doc?=	build
.endif # GTK_DOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-doc
