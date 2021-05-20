# $NetBSD: buildlink3.mk,v 1.1 2021/05/20 19:52:31 nia Exp $

BUILDLINK_TREE+=	cglm

.if !defined(CGLM_BUILDLINK3_MK)
CGLM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cglm+=	cglm>=0.8.2
BUILDLINK_PKGSRCDIR.cglm?=	../../graphics/cglm
.endif	# CGLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cglm
