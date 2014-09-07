# $NetBSD: buildlink3.mk,v 1.3 2014/09/07 20:14:12 wiz Exp $

BUILDLINK_TREE+=	dialog

.if !defined(DIALOG_BUILDLINK3_MK)
DIALOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dialog+=	dialog>=1.1.20080819nb1
BUILDLINK_PKGSRCDIR.dialog?=	../../misc/dialog

.include "../../mk/curses.buildlink3.mk"
.endif # DIALOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-dialog
