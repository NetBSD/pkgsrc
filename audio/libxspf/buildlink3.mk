# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:03:55 rillig Exp $

BUILDLINK_TREE+=	libspiff

.if !defined(LIBSPIFF_BUILDLINK3_MK)
LIBSPIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspiff+=	libxspf>=1.2.0
BUILDLINK_PKGSRCDIR.libspiff?=		../../audio/libxspf

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"
.endif # LIBSPIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspiff
