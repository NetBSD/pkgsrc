# $NetBSD: buildlink3.mk,v 1.14 2009/10/27 14:50:07 drochner Exp $

BUILDLINK_TREE+=	gnome-doc-utils

.if !defined(GNOME_DOC_UTILS_BUILDLINK3_MK)
GNOME_DOC_UTILS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.gnome-doc-utils+=	build
BUILDLINK_API_DEPENDS.gnome-doc-utils+=	gnome-doc-utils>=0.8.0
BUILDLINK_PKGSRCDIR.gnome-doc-utils?=	../../textproc/gnome-doc-utils

# doesn't work yet
#.include "../../textproc/libxslt/xsltproc-nonet.mk"
.endif # GNOME_DOC_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-doc-utils
