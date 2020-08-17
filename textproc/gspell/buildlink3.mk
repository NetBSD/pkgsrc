# $NetBSD: buildlink3.mk,v 1.14 2020/08/17 20:17:45 leot Exp $

BUILDLINK_TREE+=	gspell

.if !defined(GSPELL_BUILDLINK3_MK)
GSPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gspell+=	gspell>=1.0.1
BUILDLINK_ABI_DEPENDS.gspell?=	gspell>=1.8.3nb4
BUILDLINK_PKGSRCDIR.gspell?=	../../textproc/gspell

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GSPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gspell
