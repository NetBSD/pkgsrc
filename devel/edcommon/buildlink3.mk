# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:21 dholland Exp $

BUILDLINK_TREE+=	edcommon

.if !defined(EDCOMMON_BUILDLINK3_MK)
EDCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edcommon+=	edcommon>=32nb6
BUILDLINK_ABI_DEPENDS.edcommon+=	edcommon>=32nb6
BUILDLINK_PKGSRCDIR.edcommon?=	../../devel/edcommon
.endif # EDCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-edcommon
