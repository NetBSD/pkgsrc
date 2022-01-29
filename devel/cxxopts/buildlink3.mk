# $NetBSD: buildlink3.mk,v 1.2 2022/01/29 08:12:46 nros Exp $

BUILDLINK_TREE+=	cxxopts

.if !defined(CXXOPTS_BUILDLINK3_MK)
CXXOPTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cxxopts+=	cxxopts>=3.0.0
BUILDLINK_PKGSRCDIR.cxxopts?=	../../devel/cxxopts
BUILDLINK_DEPMETHOD.cxxopts?=	build
.endif

BUILDLINK_TREE+=	-cxxopts
