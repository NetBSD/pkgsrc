# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:23:57 joerg Exp $

BUILDLINK_TREE+=	libspiff

.if !defined(LIBSPIFF_BUILDLINK3_MK)
LIBSPIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspiff+=	libspiff>=1.0.0
BUILDLINK_PKGSRCDIR.libspiff?=	../../audio/libspiff

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"
.endif # LIBSPIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspiff
