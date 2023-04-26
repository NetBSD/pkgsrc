# $NetBSD: buildlink3.mk,v 1.2 2023/04/26 19:57:06 wiz Exp $

BUILDLINK_TREE+=	tomlplusplus

.if !defined(TOMLPLUSPLUS_BUILDLINK3_MK)
TOMLPLUSPLUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tomlplusplus+=	tomlplusplus>=3.3.0
BUILDLINK_PKGSRCDIR.tomlplusplus?=	../../devel/tomlplusplus

.endif	# TOMLPLUSPLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tomlplusplus
