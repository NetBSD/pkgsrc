# $NetBSD: buildlink3.mk,v 1.3 2011/10/27 10:32:56 ryoon Exp $

BUILDLINK_TREE+=	djvulibre-lib

.if !defined(DJVULIBRE_LIB_BUILDLINK3_MK)
DJVULIBRE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.djvulibre-lib+=	djvulibre-lib>=3.5.24
BUILDLINK_PKGSRCDIR.djvulibre-lib?=	../../graphics/djvulibre-lib
.endif # DJVULIBRE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-djvulibre-lib
