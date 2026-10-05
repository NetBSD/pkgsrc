# $NetBSD: buildlink3.mk,v 1.1 2026/10/05 13:13:35 ktnb Exp $

BUILDLINK_TREE+=	plog

.if !defined(PLOG_BUILDLINK3_MK)
PLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plog+=	plog>=1.1.11
BUILDLINK_PKGSRCDIR.plog?=	../../devel/plog

BUILDLINK_DEPMETHOD.plog?=	build
.endif	# PLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-plog
