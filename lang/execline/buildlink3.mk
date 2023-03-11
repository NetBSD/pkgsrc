# $NetBSD: buildlink3.mk,v 1.5 2023/03/11 15:47:34 schmonz Exp $

BUILDLINK_TREE+=	execline

.if !defined(EXECLINE_BUILDLINK3_MK)
EXECLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.execline+=	execline>=2.9.2.0
BUILDLINK_PKGSRCDIR.execline?=		../../lang/execline
BUILDLINK_DEPMETHOD.execline?=		build
.endif # EXECLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-execline
