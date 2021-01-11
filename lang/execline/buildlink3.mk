# $NetBSD: buildlink3.mk,v 1.2 2021/01/11 18:23:54 schmonz Exp $

BUILDLINK_TREE+=	execline

.if !defined(EXECLINE_BUILDLINK3_MK)
EXECLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.execline+=	execline>=2.7.0.0
BUILDLINK_PKGSRCDIR.execline?=		../../lang/execline
BUILDLINK_DEPMETHOD.execline?=		build
.endif # EXECLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-execline
