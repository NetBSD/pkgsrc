# $NetBSD: buildlink3.mk,v 1.3 2023/07/20 21:29:00 nia Exp $
#

BUILDLINK_TREE+=	opencc

.if !defined(OPENCC_BUILDLINK3_MK)
OPENCC_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_API_DEPENDS.opencc+=	opencc>=1.1.1
BUILDLINK_PKGSRCDIR.opencc?=	../../converters/opencc
.endif	# OPENCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencc
