# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:00 joerg Exp $

BUILDLINK_TREE+=	dialog

.if !defined(DIALOG_BUILDLINK3_MK)
DIALOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dialog+=	dialog>=1.1.20080819nb1
BUILDLINK_PKGSRCDIR.dialog?=	../../misc/dialog

.include "../../devel/ncurses/buildlink3.mk"
.endif # DIALOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-dialog
