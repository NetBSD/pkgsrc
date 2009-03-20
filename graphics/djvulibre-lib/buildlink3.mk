# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:37 joerg Exp $

BUILDLINK_TREE+=	djvulibre-lib

.if !defined(DJVULIBRE_LIB_BUILDLINK3_MK)
DJVULIBRE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.djvulibre-lib+=	djvulibre-lib>=3.5.17
BUILDLINK_PKGSRCDIR.djvulibre-lib?=	../../graphics/djvulibre-lib
.endif # DJVULIBRE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-djvulibre-lib
