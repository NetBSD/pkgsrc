# $NetBSD: buildlink3.mk,v 1.2 2017/08/17 13:49:15 schmonz Exp $

BUILDLINK_TREE+=	libidn2

.if !defined(LIBIDN2_BUILDLINK3_MK)
LIBIDN2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libidn2+=	libidn2>=2.0.0
BUILDLINK_PKGSRCDIR.libidn2?=	../../devel/libidn2

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.endif	# LIBIDN2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libidn2
