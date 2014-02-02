# $NetBSD: buildlink3.mk,v 1.1 2014/02/02 07:31:30 ryoon Exp $

BUILDLINK_TREE+=	libfreehand

.if !defined(LIBFREEHAND_BUILDLINK3_MK)
LIBFREEHAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfreehand+=	libfreehand>=0.0.0
BUILDLINK_PKGSRCDIR.libfreehand?=	../../converters/libfreehand

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.endif	# LIBFREEHAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfreehand
