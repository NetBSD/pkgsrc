# $NetBSD: buildlink3.mk,v 1.22 2022/11/23 16:19:02 adam Exp $

BUILDLINK_TREE+=	ebook-tools

.if !defined(EBOOK_TOOLS_BUILDLINK3_MK)
EBOOK_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ebook-tools+=	ebook-tools>=0.1.1
BUILDLINK_ABI_DEPENDS.ebook-tools+=	ebook-tools>=0.2.2nb17
BUILDLINK_PKGSRCDIR.ebook-tools?=	../../textproc/ebook-tools

.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # EBOOK_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ebook-tools
