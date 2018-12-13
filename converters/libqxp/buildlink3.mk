# $NetBSD: buildlink3.mk,v 1.4 2018/12/13 19:51:32 adam Exp $

BUILDLINK_TREE+=	libqxp

.if !defined(LIBQXP_BUILDLINK3_MK)
LIBQXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libqxp+=	libqxp>=0.0.1
BUILDLINK_ABI_DEPENDS.libqxp?=	libqxp>=0.0.1nb6
BUILDLINK_PKGSRCDIR.libqxp?=	../../converters/libqxp

.include "../../converters/librevenge/buildlink3.mk"
.endif	# LIBQXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libqxp
