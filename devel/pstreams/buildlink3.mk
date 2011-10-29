# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/29 10:39:31 ryoon Exp $

BUILDLINK_TREE+=	pstreams

.if !defined(PSTREAMS_BUILDLINK3_MK)
PSTREAMS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.pstreams?=	build

BUILDLINK_API_DEPENDS.pstreams+=	pstreams>=0.7.0
BUILDLINK_PKGSRCDIR.pstreams?=	../../devel/pstreams
.endif	# PSTREAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pstreams
