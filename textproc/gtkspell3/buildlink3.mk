# $NetBSD: buildlink3.mk,v 1.1 2018/08/25 12:03:21 wiz Exp $

BUILDLINK_TREE+=	gtkspell3

.if !defined(GTKSPELL3_BUILDLINK3_MK)
GTKSPELL3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkspell3+=	gtkspell3>=3.0
BUILDLINK_PKGSRCDIR.gtkspell3?=		../../textproc/gtkspell3

.include "../../textproc/enchant/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # GTKSPELL3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkspell3
