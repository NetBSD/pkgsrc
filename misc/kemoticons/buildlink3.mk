# $NetBSD: buildlink3.mk,v 1.27 2023/10/24 22:09:59 wiz Exp $

BUILDLINK_TREE+=	kemoticons

.if !defined(KEMOTICONS_BUILDLINK3_MK)
KEMOTICONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kemoticons+=	kemoticons>=5.19.0
BUILDLINK_ABI_DEPENDS.kemoticons?=	kemoticons>=5.108.0nb1
BUILDLINK_PKGSRCDIR.kemoticons?=	../../misc/kemoticons

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KEMOTICONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kemoticons
