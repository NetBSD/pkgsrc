# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:12 joerg Exp $

BUILDLINK_TREE+=	edcommon

.if !defined(EDCOMMON_BUILDLINK3_MK)
EDCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edcommon+=	edcommon>=32
BUILDLINK_ABI_DEPENDS.edcommon?=	edcommon>=32nb2
BUILDLINK_PKGSRCDIR.edcommon?=	../../devel/edcommon
.endif # EDCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-edcommon
