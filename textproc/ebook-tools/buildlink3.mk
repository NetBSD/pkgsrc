# $NetBSD: buildlink3.mk,v 1.4 2012/06/14 07:43:21 sbd Exp $

BUILDLINK_TREE+=	ebook-tools

.if !defined(EBOOK_TOOLS_BUILDLINK3_MK)
EBOOK_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ebook-tools+=	ebook-tools>=0.1.1
BUILDLINK_ABI_DEPENDS.ebook-tools+=	ebook-tools>=0.1.1nb3
BUILDLINK_PKGSRCDIR.ebook-tools?=	../../textproc/ebook-tools

.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # EBOOK_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ebook-tools
