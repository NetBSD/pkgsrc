# $NetBSD: buildlink3.mk,v 1.2 2025/09/27 09:57:13 wiz Exp $

BUILDLINK_TREE+=	immer

.if !defined(IMMER_BUILDLINK3_MK)
IMMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.immer+=	immer>=0.8.1
BUILDLINK_DEPMETHOD.immer?=	build
BUILDLINK_ABI_DEPENDS.immer?=	immer>=0.8.1nb2
BUILDLINK_PKGSRCDIR.immer?=	../../devel/immer

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# IMMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-immer
