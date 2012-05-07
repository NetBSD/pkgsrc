# $NetBSD: buildlink3.mk,v 1.17 2012/05/07 01:53:33 dholland Exp $

BUILDLINK_TREE+=	freetype

.if !defined(FREETYPE_BUILDLINK3_MK)
FREETYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetype+=	freetype-lib>=1.3.1nb1
BUILDLINK_ABI_DEPENDS.freetype+=freetype-lib>=1.3.1nb2
BUILDLINK_ABI_DEPENDS.freetype+=	freetype-lib>=1.5nb1
BUILDLINK_PKGSRCDIR.freetype?=	../../graphics/freetype-lib

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # FREETYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetype
