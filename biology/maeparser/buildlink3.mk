# $NetBSD: buildlink3.mk,v 1.13 2026/05/15 09:58:41 adam Exp $

BUILDLINK_TREE+=	maeparser

.if !defined(MAEPARSER_BUILDLINK3_MK)
MAEPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.maeparser+=	maeparser>=1.2.4
BUILDLINK_ABI_DEPENDS.maeparser?=	maeparser>=1.3.2nb2
BUILDLINK_PKGSRCDIR.maeparser?=		../../biology/maeparser

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# MAEPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-maeparser
