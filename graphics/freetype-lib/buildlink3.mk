# $NetBSD: buildlink3.mk,v 1.15 2009/03/20 19:24:38 joerg Exp $

BUILDLINK_TREE+=	freetype

.if !defined(FREETYPE_BUILDLINK3_MK)
FREETYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetype+=	freetype-lib>=1.3.1nb1
BUILDLINK_ABI_DEPENDS.freetype+=freetype-lib>=1.3.1nb2
BUILDLINK_ABI_DEPENDS.freetype?=	freetype-lib>=1.3.1nb3
BUILDLINK_PKGSRCDIR.freetype?=	../../graphics/freetype-lib

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # FREETYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetype
