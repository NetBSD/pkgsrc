# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:09 rillig Exp $

BUILDLINK_TREE+=	pstreams

.if !defined(PSTREAMS_BUILDLINK3_MK)
PSTREAMS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.pstreams?=	build

BUILDLINK_API_DEPENDS.pstreams+=	pstreams>=0.7.0
BUILDLINK_PKGSRCDIR.pstreams?=		../../devel/pstreams
.endif	# PSTREAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pstreams
