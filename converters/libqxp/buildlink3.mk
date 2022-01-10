# $NetBSD: buildlink3.mk,v 1.12 2022/01/10 01:46:26 ryoon Exp $

BUILDLINK_TREE+=	libqxp

.if !defined(LIBQXP_BUILDLINK3_MK)
LIBQXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libqxp+=	libqxp>=0.0.1
BUILDLINK_ABI_DEPENDS.libqxp?=	libqxp>=0.0.2nb14
BUILDLINK_PKGSRCDIR.libqxp?=	../../converters/libqxp

.include "../../converters/librevenge/buildlink3.mk"
.endif	# LIBQXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libqxp
