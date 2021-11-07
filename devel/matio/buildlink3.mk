# $NetBSD: buildlink3.mk,v 1.3 2021/11/07 10:50:38 nros Exp $

BUILDLINK_TREE+=	matio

.if !defined(MATIO_BUILDLINK3_MK)
MATIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.matio+=	matio>=1.5.12
BUILDLINK_PKGSRCDIR.matio?=	../../devel/matio

# matio.pc refer to these libs
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# MATIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-matio
