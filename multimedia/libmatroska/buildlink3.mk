# $NetBSD: buildlink3.mk,v 1.17 2009/03/20 19:25:04 joerg Exp $
#
# This Makefile fragment is included by packages that use libmatroska.
#

BUILDLINK_TREE+=	libmatroska

.if !defined(LIBMATROSKA_BUILDLINK3_MK)
LIBMATROSKA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatroska+=	libmatroska>=0.8.0
BUILDLINK_ABI_DEPENDS.libmatroska?=	libmatroska>=0.8.0nb1
BUILDLINK_PKGSRCDIR.libmatroska?=	../../multimedia/libmatroska

.include "../../devel/libebml/buildlink3.mk"
.endif # LIBMATROSKA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatroska
