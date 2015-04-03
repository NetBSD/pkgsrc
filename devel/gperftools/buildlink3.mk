# $NetBSD: buildlink3.mk,v 1.1 2015/04/03 17:20:53 hiramatsu Exp $

BUILDLINK_TREE+=	gperftools

.if !defined(GPERFTOOLS_BUILDLINK3_MK)
GPERFTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gperftools+=	gperftools>=2.4
BUILDLINK_PKGSRCDIR.gperftools?=	../../devel/gperftools
.endif	# GPERFTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gperftools
