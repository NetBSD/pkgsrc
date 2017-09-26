# $NetBSD: buildlink3.mk,v 1.1 2017/09/26 17:38:22 minskim Exp $

BUILDLINK_TREE+=	blosc

.if !defined(BLOSC_BUILDLINK3_MK)
BLOSC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blosc+=	blosc>=1.12.1
BUILDLINK_PKGSRCDIR.blosc?=	../../devel/blosc

.endif	# BLOSC_BUILDLINK3_MK

BUILDLINK_TREE+=	-blosc
