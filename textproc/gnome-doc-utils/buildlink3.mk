# $NetBSD: buildlink3.mk,v 1.15 2023/08/14 05:25:22 wiz Exp $

BUILDLINK_TREE+=	gnome-doc-utils

.if !defined(GNOME_DOC_UTILS_BUILDLINK3_MK)
GNOME_DOC_UTILS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.gnome-doc-utils+=	build
BUILDLINK_API_DEPENDS.gnome-doc-utils+=	gnome-doc-utils>=0.8.0
BUILDLINK_ABI_DEPENDS.gnome-doc-utils?=	gnome-doc-utils>=0.20.10nb15
BUILDLINK_PKGSRCDIR.gnome-doc-utils?=	../../textproc/gnome-doc-utils

# doesn't work yet
#.include "../../textproc/libxslt/xsltproc-nonet.mk"
.endif # GNOME_DOC_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-doc-utils
