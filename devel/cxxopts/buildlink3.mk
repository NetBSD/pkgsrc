# $NetBSD: buildlink3.mk,v 1.1 2021/12/31 17:23:19 plunky Exp $

BUILDLINK_TREE+=	cxxopts

.if !defined(CXXOPTS_BUILDLINK3_MK)
CXXOPTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cxxopts+=	cxxopts>=3.0.0
BUILDLINK_PKGSRCDIR.cxxopts?=	../../devel/cxxopts
.endif

BUILDLINK_TREE+=	-cxxopts
