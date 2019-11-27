# $NetBSD: buildlink3.mk,v 1.1 2019/11/27 21:23:53 markd Exp $

BUILDLINK_TREE+=	rttr

.if !defined(RTTR_BUILDLINK3_MK)
RTTR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rttr+=	rttr>=0.9.6
BUILDLINK_PKGSRCDIR.rttr?=	../../devel/rttr
.endif	# RTTR_BUILDLINK3_MK

BUILDLINK_TREE+=	-rttr
