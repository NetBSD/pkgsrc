# $NetBSD: buildlink3.mk,v 1.10 2024/12/29 15:09:39 adam Exp $

BUILDLINK_TREE+=	maeparser

.if !defined(MAEPARSER_BUILDLINK3_MK)
MAEPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.maeparser+=	maeparser>=1.2.4
BUILDLINK_ABI_DEPENDS.maeparser?=	maeparser>=1.2.4nb9
BUILDLINK_PKGSRCDIR.maeparser?=	../../biology/maeparser

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# MAEPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-maeparser
