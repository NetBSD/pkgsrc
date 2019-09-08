# $NetBSD: buildlink3.mk,v 1.1 2019/09/08 12:27:08 nia Exp $

BUILDLINK_TREE+=	p8-platform

.if !defined(P8_PLATFORM_BUILDLINK3_MK)
P8_PLATFORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p8-platform+=	p8-platform>=2.1.0.1
BUILDLINK_PKGSRCDIR.p8-platform?=	../../devel/p8-platform
BUILDLINK_DEPMETHOD.p8-platform?=	build
.endif	# P8_PLATFORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-p8-platform
