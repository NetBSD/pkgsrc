# $NetBSD: buildlink3.mk,v 1.1 2023/11/15 15:23:13 nia Exp $

BUILDLINK_TREE+=	macports-legacy-support

.if !defined(MACPORTS_LEGACY_SUPPORT_BUILDLINK3_MK)
MACPORTS_LEGACY_SUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.macports-legacy-support+=	macports-legacy-support>=1.1.1
BUILDLINK_PKGSRCDIR.macports-legacy-support?=	../../devel/macports-legacy-support
BUILDLINK_INCDIRS.macports-legacy-support+=	include/LegacySupport
.endif	# MACPORTS_LEGACY_SUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-macports-legacy-support
