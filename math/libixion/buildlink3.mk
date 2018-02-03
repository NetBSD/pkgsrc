# $NetBSD: buildlink3.mk,v 1.3 2018/02/03 00:26:13 ryoon Exp $

BUILDLINK_TREE+=	libixion

.if !defined(LIBIXION_BUILDLINK3_MK)
LIBIXION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libixion+=	libixion>=0.13.0
BUILDLINK_PKGSRCDIR.libixion?=		../../math/libixion

.include "../../devel/mdds1.2/buildlink3.mk"
.endif	# LIBIXION_BUILDLINK3_MK

BUILDLINK_TREE+=	-libixion
