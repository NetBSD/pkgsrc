# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:43 joerg Exp $

BUILDLINK_TREE+=	libotf

.if !defined(LIBOTF_BUILDLINK3_MK)
LIBOTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libotf+=	libotf>=0.9.7
BUILDLINK_PKGSRCDIR.libotf?=	../../graphics/libotf

.include "../../graphics/freetype2/buildlink3.mk"
.endif # LIBOTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libotf
