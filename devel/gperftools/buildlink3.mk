# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:44 wiz Exp $

BUILDLINK_TREE+=	gperftools

.if !defined(GPERFTOOLS_BUILDLINK3_MK)
GPERFTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gperftools+=	gperftools>=2.4
BUILDLINK_ABI_DEPENDS.gperftools?=	gperftools>=2.9.1nb2
BUILDLINK_PKGSRCDIR.gperftools?=	../../devel/gperftools
.endif	# GPERFTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gperftools
