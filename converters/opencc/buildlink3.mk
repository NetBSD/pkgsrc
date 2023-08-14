# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:23:57 wiz Exp $
#

BUILDLINK_TREE+=	opencc

.if !defined(OPENCC_BUILDLINK3_MK)
OPENCC_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_API_DEPENDS.opencc+=	opencc>=1.1.1
BUILDLINK_ABI_DEPENDS.opencc?=	opencc>=1.1.3nb1
BUILDLINK_PKGSRCDIR.opencc?=	../../converters/opencc
.endif	# OPENCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencc
