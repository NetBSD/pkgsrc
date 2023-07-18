# $NetBSD: buildlink3.mk,v 1.3 2023/07/18 14:11:17 nia Exp $

BUILDLINK_TREE+=	tomlplusplus

.if !defined(TOMLPLUSPLUS_BUILDLINK3_MK)
TOMLPLUSPLUS_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

BUILDLINK_API_DEPENDS.tomlplusplus+=	tomlplusplus>=3.3.0
BUILDLINK_PKGSRCDIR.tomlplusplus?=	../../devel/tomlplusplus

.endif	# TOMLPLUSPLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tomlplusplus
