# $NetBSD: buildlink3.mk,v 1.26 2026/09/02 19:04:42 wiz Exp $

BUILDLINK_TREE+=	gtkspell3

.if !defined(GTKSPELL3_BUILDLINK3_MK)
GTKSPELL3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkspell3+=	gtkspell3>=3.0
BUILDLINK_ABI_DEPENDS.gtkspell3?=	gtkspell3>=3.0.10nb23
BUILDLINK_PKGSRCDIR.gtkspell3?=		../../textproc/gtkspell3

.include "../../textproc/enchant2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # GTKSPELL3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkspell3
