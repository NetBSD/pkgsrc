# $NetBSD: buildlink3.mk,v 1.18 2024/05/09 01:32:49 pho Exp $

BUILDLINK_TREE+=	hs-xml

.if !defined(HS_XML_BUILDLINK3_MK)
HS_XML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xml+=	hs-xml>=1.3.14
BUILDLINK_ABI_DEPENDS.hs-xml+=	hs-xml>=1.3.14nb8
BUILDLINK_PKGSRCDIR.hs-xml?=	../../textproc/hs-xml
.endif	# HS_XML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xml
