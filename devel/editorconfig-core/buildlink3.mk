# $NetBSD: buildlink3.mk,v 1.1 2017/05/28 19:43:46 nros Exp $

BUILDLINK_TREE+=	editorconfig-core

.if !defined(EDITORCONFIG_CORE_BUILDLINK3_MK)
EDITORCONFIG_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.editorconfig-core+=	editorconfig-core>=0.12.1
BUILDLINK_PKGSRCDIR.editorconfig-core?=	../../devel/editorconfig-core
.endif	# EDITORCONFIG_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-editorconfig-core
