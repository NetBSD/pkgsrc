# $NetBSD: buildlink3.mk,v 1.1 2015/07/04 05:17:56 ryoon Exp $

BUILDLINK_TREE+=	npth

.if !defined(NPTH_BUILDLINK3_MK)
NPTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.npth+=	npth>=1.1
BUILDLINK_PKGSRCDIR.npth?=	../../devel/npth
.endif	# NPTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-npth
