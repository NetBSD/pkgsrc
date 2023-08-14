# $NetBSD: buildlink3.mk,v 1.10 2023/08/14 05:24:24 wiz Exp $

BUILDLINK_TREE+=	mftrace

.if !defined(MFTRACE_BUILDLINK3_MK)
MFTRACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mftrace+=	mftrace>=1.0.19
BUILDLINK_ABI_DEPENDS.mftrace+=	mftrace>=1.2.19nb3
BUILDLINK_PKGSRCDIR.mftrace?=	../../fonts/mftrace
.endif # MFTRACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mftrace
