# $NetBSD: buildlink3.mk,v 1.1 2026/06/18 22:03:18 js Exp $

BUILDLINK_TREE+=	gemtext2html

.if !defined(GEMTEXT2HTML_BUILDLINK3_MK)
GEMTEXT2HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gemtext2html+=	gemtext2html>=0.1
BUILDLINK_ABI_DEPENDS.gemtext2html+=	gemtext2html>=0.1
BUILDLINK_PKGSRCDIR.gemtext2html?=	../../textproc/gemtext2html
.endif

BUILDLINK_TREE+=	-gemtext2html
