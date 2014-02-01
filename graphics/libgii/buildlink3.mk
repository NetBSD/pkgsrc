# $NetBSD: buildlink3.mk,v 1.13 2014/02/01 19:39:17 joerg Exp $

BUILDLINK_TREE+=	libgii

.if !defined(LIBGII_BUILDLINK3_MK)
LIBGII_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgii+=	libgii>=1.0.2
BUILDLINK_PKGSRCDIR.libgii?=	../../graphics/libgii

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.endif # LIBGII_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgii
