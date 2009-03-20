# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:31 joerg Exp $

BUILDLINK_TREE+=	mxml

.if !defined(MXML_BUILDLINK3_MK)
MXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mxml+=	mxml>=2.3
BUILDLINK_PKGSRCDIR.mxml?=	../../textproc/mxml
.endif # MXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-mxml
