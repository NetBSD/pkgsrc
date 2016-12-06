# $NetBSD: buildlink3.mk,v 1.1 2016/12/06 00:34:18 rodent Exp $

BUILDLINK_TREE+=	gflags

.if !defined(GFLAGS_BUILDLINK3_MK)
GFLAGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gflags+=	gflags>=2.1.2
BUILDLINK_PKGSRCDIR.gflags?=	../../devel/gflags
.endif	# GFLAGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gflags
