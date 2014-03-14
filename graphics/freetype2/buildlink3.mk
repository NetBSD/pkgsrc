# $NetBSD: buildlink3.mk,v 1.40 2014/03/14 13:38:20 ryoon Exp $

BUILDLINK_TREE+=	freetype2

.if !defined(FREETYPE2_BUILDLINK3_MK)
FREETYPE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.4.5
BUILDLINK_ABI_DEPENDS.freetype2+=	freetype2>=2.4.12
BUILDLINK_PKGSRCDIR.freetype2?=	../../graphics/freetype2
BUILDLINK_INCDIRS.freetype2?=	include/freetype2

BUILDLINK_FILES.freetype2+=	bin/freetype-config

FREETYPE_CONFIG?=	${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
CONFIGURE_ENV+=		FREETYPE_CONFIG=${FREETYPE_CONFIG:Q}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.if empty(USE_BUILTIN.freetype2:M[yY][eE][sS])
.include "../../graphics/png/buildlink3.mk"
.endif
.endif # FREETYPE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetype2
