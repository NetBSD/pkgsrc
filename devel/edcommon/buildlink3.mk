# $NetBSD: buildlink3.mk,v 1.11 2018/01/07 13:04:01 rillig Exp $

BUILDLINK_TREE+=	edcommon

.if !defined(EDCOMMON_BUILDLINK3_MK)
EDCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edcommon+=	edcommon>=32nb6
BUILDLINK_ABI_DEPENDS.edcommon+=	edcommon>=32nb6
BUILDLINK_PKGSRCDIR.edcommon?=		../../devel/edcommon
.endif # EDCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-edcommon
