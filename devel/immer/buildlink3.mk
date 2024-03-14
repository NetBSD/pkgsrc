# $NetBSD: buildlink3.mk,v 1.1 2024/03/14 19:24:15 markd Exp $

BUILDLINK_TREE+=	immer

.if !defined(IMMER_BUILDLINK3_MK)
IMMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.immer+=	immer>=0.8.1
BUILDLINK_DEPMETHOD.immer?=	build
BUILDLINK_PKGSRCDIR.immer?=	../../devel/immer

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# IMMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-immer
