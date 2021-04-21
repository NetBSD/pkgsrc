# $NetBSD: buildlink3.mk,v 1.21 2021/04/21 11:40:30 adam Exp $

BUILDLINK_TREE+=	kemoticons

.if !defined(KEMOTICONS_BUILDLINK3_MK)
KEMOTICONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kemoticons+=	kemoticons>=5.19.0
BUILDLINK_ABI_DEPENDS.kemoticons?=	kemoticons>=5.80.0nb1
BUILDLINK_PKGSRCDIR.kemoticons?=	../../misc/kemoticons

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KEMOTICONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kemoticons
