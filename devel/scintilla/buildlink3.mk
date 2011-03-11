# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/03/11 14:38:22 drochner Exp $

BUILDLINK_DEPMETHOD.scintilla?=	build

BUILDLINK_TREE+=	scintilla

.if !defined(SCINTILLA_BUILDLINK3_MK)
SCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scintilla+=	scintilla>=2.23
BUILDLINK_PKGSRCDIR.scintilla?=	../../devel/scintilla

#.include "../../x11/gtk2/buildlink3.mk"
.endif	# SCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-scintilla
