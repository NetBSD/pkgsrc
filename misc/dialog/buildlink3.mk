# $NetBSD: buildlink3.mk,v 1.4 2015/08/18 07:31:01 wiz Exp $

BUILDLINK_TREE+=	dialog

.if !defined(DIALOG_BUILDLINK3_MK)
DIALOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dialog+=	dialog>=1.1.20080819nb1
BUILDLINK_ABI_DEPENDS.dialog?=	dialog>=1.2.20150528nb2
BUILDLINK_PKGSRCDIR.dialog?=	../../misc/dialog

.include "../../mk/curses.buildlink3.mk"
.endif # DIALOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-dialog
