# $NetBSD: buildlink3.mk,v 1.3 2016/03/08 13:50:46 nros Exp $

BUILDLINK_TREE+=	mxml

.if !defined(MXML_BUILDLINK3_MK)
MXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mxml+=	mxml>=2.3
BUILDLINK_ABI_DEPENDS.mxml+=	mxml>=2.9
BUILDLINK_PKGSRCDIR.mxml?=	../../textproc/mxml
.endif # MXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-mxml
