# $NetBSD: buildlink3.mk,v 1.3 2017/02/06 13:54:38 wiz Exp $

BUILDLINK_TREE+=	kbookmarks

.if !defined(KBOOKMARKS_BUILDLINK3_MK)
KBOOKMARKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kbookmarks+=	kbookmarks>=5.19.0
BUILDLINK_ABI_DEPENDS.kbookmarks?=	kbookmarks>=5.25.0nb3
BUILDLINK_PKGSRCDIR.kbookmarks?=	../../devel/kbookmarks

.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KBOOKMARKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kbookmarks
