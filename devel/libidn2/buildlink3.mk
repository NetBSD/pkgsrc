# $NetBSD: buildlink3.mk,v 1.3 2017/08/18 21:04:51 adam Exp $

BUILDLINK_TREE+=	libidn2

.if !defined(LIBIDN2_BUILDLINK3_MK)
LIBIDN2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libidn2+=	libidn2>=2.0.0
BUILDLINK_PKGSRCDIR.libidn2?=	../../devel/libidn2

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.endif	# LIBIDN2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libidn2
