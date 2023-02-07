# $NetBSD: buildlink3.mk,v 1.6 2023/02/07 01:41:15 pho Exp $

BUILDLINK_TREE+=	hs-xml-types

.if !defined(HS_XML_TYPES_BUILDLINK3_MK)
HS_XML_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xml-types+=	hs-xml-types>=0.3.8
BUILDLINK_ABI_DEPENDS.hs-xml-types+=	hs-xml-types>=0.3.8nb5
BUILDLINK_PKGSRCDIR.hs-xml-types?=	../../textproc/hs-xml-types
.endif	# HS_XML_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xml-types
