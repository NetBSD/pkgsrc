# $NetBSD: buildlink3.mk,v 1.36 2023/04/19 08:08:13 adam Exp $

BUILDLINK_TREE+=	kbookmarks

.if !defined(KBOOKMARKS_BUILDLINK3_MK)
KBOOKMARKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kbookmarks+=	kbookmarks>=5.19.0
BUILDLINK_ABI_DEPENDS.kbookmarks?=	kbookmarks>=5.98.0nb4
BUILDLINK_PKGSRCDIR.kbookmarks?=	../../devel/kbookmarks

.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KBOOKMARKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kbookmarks
