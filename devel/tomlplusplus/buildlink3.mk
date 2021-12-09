# $NetBSD: buildlink3.mk,v 1.1 2021/12/09 16:28:33 wiz Exp $

BUILDLINK_TREE+=	tomlplusplus

.if !defined(TOMLPLUSPLUS_BUILDLINK3_MK)
TOMLPLUSPLUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tomlplusplus+=	tomlplusplus>=2.5.0
BUILDLINK_PKGSRCDIR.tomlplusplus?=	../../devel/tomlplusplus

# header-only library
BUILDLINK_DEPMETHOD.tomlplusplus?=	build
.endif	# TOMLPLUSPLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tomlplusplus
