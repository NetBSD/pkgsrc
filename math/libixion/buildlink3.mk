# $NetBSD: buildlink3.mk,v 1.12 2025/09/27 09:57:27 wiz Exp $

BUILDLINK_TREE+=	libixion

.if !defined(LIBIXION_BUILDLINK3_MK)
LIBIXION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libixion+=	libixion>=0.20.0
BUILDLINK_ABI_DEPENDS.libixion?=		libixion>=0.20.0nb2
BUILDLINK_PKGSRCDIR.libixion?=		../../math/libixion

.include "../../devel/mdds/buildlink3.mk"
.endif	# LIBIXION_BUILDLINK3_MK

BUILDLINK_TREE+=	-libixion
