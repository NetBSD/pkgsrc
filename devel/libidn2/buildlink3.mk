# $NetBSD: buildlink3.mk,v 1.5 2022/10/30 11:19:21 adam Exp $

BUILDLINK_TREE+=	libidn2

.if !defined(LIBIDN2_BUILDLINK3_MK)
LIBIDN2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libidn2+=	libidn2>=2.0.0
BUILDLINK_ABI_DEPENDS.libidn2+=	libidn2>=2.3.3nb1
BUILDLINK_PKGSRCDIR.libidn2?=	../../devel/libidn2

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.endif	# LIBIDN2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libidn2
