# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 13:07:13 mef Exp $

BUILDLINK_TREE+=	gr-fcdproplus

.if !defined(GR_FCDPROPLUS_BUILDLINK3_MK)
GR_FCDPROPLUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gr-fcdproplus+=	gr-fcdproplus>=0.1
BUILDLINK_ABI_DEPENDS.gr-fcdproplus+=	gr-fcdproplus>=0.1
BUILDLINK_PKGSRCDIR.gr-fcdproplus?=	../../ham/gr-fcdproplus
.endif # GR_FCDPROPLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gr-fcdproplus
