# $NetBSD: buildlink3.mk,v 1.1 2014/02/02 07:29:34 ryoon Exp $

BUILDLINK_TREE+=	libetonyek

.if !defined(LIBETONYEK_BUILDLINK3_MK)
LIBETONYEK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libetonyek+=	libetonyek>=0.0.3
BUILDLINK_PKGSRCDIR.libetonyek?=	../../converters/libetonyek

.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBETONYEK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libetonyek
