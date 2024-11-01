# $NetBSD: buildlink3.mk,v 1.28 2024/11/01 12:54:35 wiz Exp $

BUILDLINK_TREE+=	ebook-tools

.if !defined(EBOOK_TOOLS_BUILDLINK3_MK)
EBOOK_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ebook-tools+=	ebook-tools>=0.1.1
BUILDLINK_ABI_DEPENDS.ebook-tools+=	ebook-tools>=0.2.2nb24
BUILDLINK_PKGSRCDIR.ebook-tools?=	../../textproc/ebook-tools

.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # EBOOK_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ebook-tools
