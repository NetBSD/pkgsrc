# $NetBSD: buildlink3.mk,v 1.59 2025/08/30 22:46:24 wiz Exp $

BUILDLINK_TREE+=	gtkspell

.if !defined(GTKSPELL_BUILDLINK3_MK)
GTKSPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkspell+=	gtkspell>=2.0.13
BUILDLINK_ABI_DEPENDS.gtkspell+=	gtkspell>=2.0.16nb46
BUILDLINK_PKGSRCDIR.gtkspell?=		../../textproc/gtkspell

.include "../../textproc/enchant2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKSPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkspell
