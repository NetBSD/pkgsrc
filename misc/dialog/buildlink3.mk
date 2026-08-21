# $NetBSD: buildlink3.mk,v 1.5 2026/08/21 10:27:56 adam Exp $

BUILDLINK_TREE+=	dialog

.if !defined(DIALOG_BUILDLINK3_MK)
DIALOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dialog+=	dialog>=1.1.20080819nb1
BUILDLINK_ABI_DEPENDS.dialog+=	dialog>=1.2.20150528nb2
BUILDLINK_PKGSRCDIR.dialog?=	../../misc/dialog

.include "../../mk/curses.buildlink3.mk"
.endif # DIALOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-dialog
