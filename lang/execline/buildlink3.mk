# $NetBSD: buildlink3.mk,v 1.8 2024/11/14 14:11:55 schmonz Exp $

BUILDLINK_TREE+=	execline

.if !defined(EXECLINE_BUILDLINK3_MK)
EXECLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.execline+=	execline>=2.9.6.1
BUILDLINK_PKGSRCDIR.execline?=		../../lang/execline
BUILDLINK_DEPMETHOD.execline?=		build
.endif # EXECLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-execline
