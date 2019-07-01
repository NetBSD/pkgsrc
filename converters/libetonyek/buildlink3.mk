# $NetBSD: buildlink3.mk,v 1.14 2019/07/01 04:07:45 ryoon Exp $

BUILDLINK_TREE+=	libetonyek

.if !defined(LIBETONYEK_BUILDLINK3_MK)
LIBETONYEK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libetonyek+=	libetonyek>=0.0.3
BUILDLINK_ABI_DEPENDS.libetonyek?=	libetonyek>=0.1.9nb1
BUILDLINK_PKGSRCDIR.libetonyek?=	../../converters/libetonyek

.include "../../converters/librevenge/buildlink3.mk"
.endif	# LIBETONYEK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libetonyek
