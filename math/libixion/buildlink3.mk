# $NetBSD: buildlink3.mk,v 1.1 2016/09/20 10:43:02 wiz Exp $

BUILDLINK_TREE+=	libixion

.if !defined(LIBIXION_BUILDLINK3_MK)
LIBIXION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libixion+=	libixion>=0.12.1
BUILDLINK_PKGSRCDIR.libixion?=	../../math/libixion

.include "../../devel/mdds1.2/buildlink3.mk"
.endif	# LIBIXION_BUILDLINK3_MK

BUILDLINK_TREE+=	-libixion
