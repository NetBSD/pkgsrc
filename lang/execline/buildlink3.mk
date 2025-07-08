# $NetBSD: buildlink3.mk,v 1.9 2025/07/08 21:14:28 schmonz Exp $

BUILDLINK_TREE+=	execline

.if !defined(EXECLINE_BUILDLINK3_MK)
EXECLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.execline+=	execline>=2.9.7.0nb1
BUILDLINK_PKGSRCDIR.execline?=		../../lang/execline
.endif # EXECLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-execline
