# $NetBSD: buildlink3.mk,v 1.5 2026/01/07 19:32:04 adam Exp $
#

BUILDLINK_TREE+=	opencc

.if !defined(OPENCC_BUILDLINK3_MK)
OPENCC_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_API_DEPENDS.opencc+=	opencc>=1.1.1
BUILDLINK_ABI_DEPENDS.opencc+=	opencc>=1.1.3nb1
BUILDLINK_PKGSRCDIR.opencc?=	../../converters/opencc

.include "../../textproc/marisa/buildlink3.mk"
.endif	# OPENCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencc
