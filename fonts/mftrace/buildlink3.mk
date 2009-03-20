# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:34 joerg Exp $

BUILDLINK_TREE+=	mftrace

.if !defined(MFTRACE_BUILDLINK3_MK)
MFTRACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mftrace+=	mftrace>=1.0.19
BUILDLINK_ABI_DEPENDS.mftrace?=	mftrace>=1.1.1nb3
BUILDLINK_PKGSRCDIR.mftrace?=	../../fonts/mftrace
.endif # MFTRACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mftrace
