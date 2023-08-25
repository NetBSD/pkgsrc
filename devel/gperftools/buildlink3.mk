# $NetBSD: buildlink3.mk,v 1.3 2023/08/25 16:38:42 adam Exp $

BUILDLINK_TREE+=	gperftools

.if !defined(GPERFTOOLS_BUILDLINK3_MK)
GPERFTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gperftools+=	gperftools>=2.4
BUILDLINK_ABI_DEPENDS.gperftools+=	gperftools>=2.9.1nb2
BUILDLINK_PKGSRCDIR.gperftools?=	../../devel/gperftools
.endif	# GPERFTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gperftools
