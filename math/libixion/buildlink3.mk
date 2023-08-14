# $NetBSD: buildlink3.mk,v 1.9 2023/08/14 05:24:49 wiz Exp $

BUILDLINK_TREE+=	libixion

.if !defined(LIBIXION_BUILDLINK3_MK)
LIBIXION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libixion+=	libixion>=0.17.0
BUILDLINK_ABI_DEPENDS.libixion?=		libixion>=0.17.0nb4
BUILDLINK_PKGSRCDIR.libixion?=		../../math/libixion

.include "../../devel/mdds/buildlink3.mk"
.endif	# LIBIXION_BUILDLINK3_MK

BUILDLINK_TREE+=	-libixion
