# $NetBSD: buildlink3.mk,v 1.33 2011/11/01 06:01:32 sbd Exp $

BUILDLINK_TREE+=	freetype2

.if !defined(FREETYPE2_BUILDLINK3_MK)
FREETYPE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.8
BUILDLINK_ABI_DEPENDS.freetype2+=	freetype2>=2.4.7nb2
BUILDLINK_PKGSRCDIR.freetype2?=	../../graphics/freetype2
BUILDLINK_INCDIRS.freetype2?=	include/freetype2

FREETYPE_CONFIG?=	${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
CONFIGURE_ENV+=		FREETYPE_CONFIG=${FREETYPE_CONFIG:Q}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FREETYPE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetype2
