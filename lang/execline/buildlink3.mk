# $NetBSD: buildlink3.mk,v 1.7 2024/06/19 18:58:58 schmonz Exp $

BUILDLINK_TREE+=	execline

.if !defined(EXECLINE_BUILDLINK3_MK)
EXECLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.execline+=	execline>=2.9.6.0
BUILDLINK_PKGSRCDIR.execline?=		../../lang/execline
BUILDLINK_DEPMETHOD.execline?=		build
.endif # EXECLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-execline
