# $NetBSD: buildlink3.mk,v 1.10 2023/10/15 07:08:09 ryoon Exp $

BUILDLINK_TREE+=	libixion

.if !defined(LIBIXION_BUILDLINK3_MK)
LIBIXION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libixion+=	libixion>=0.18.1
BUILDLINK_PKGSRCDIR.libixion?=		../../math/libixion

.include "../../devel/mdds/buildlink3.mk"
.endif	# LIBIXION_BUILDLINK3_MK

BUILDLINK_TREE+=	-libixion
