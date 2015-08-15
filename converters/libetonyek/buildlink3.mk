# $NetBSD: buildlink3.mk,v 1.4 2015/08/15 22:46:39 wiz Exp $

BUILDLINK_TREE+=	libetonyek

.if !defined(LIBETONYEK_BUILDLINK3_MK)
LIBETONYEK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libetonyek+=	libetonyek>=0.0.3
BUILDLINK_ABI_DEPENDS.libetonyek?=	libetonyek>=0.1.2nb1
BUILDLINK_PKGSRCDIR.libetonyek?=	../../converters/libetonyek

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.endif	# LIBETONYEK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libetonyek
