# $NetBSD: buildlink3.mk,v 1.9 2020/01/02 14:22:53 pho Exp $

BUILDLINK_TREE+=	hs-xml

.if !defined(HS_XML_BUILDLINK3_MK)
HS_XML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xml+=	hs-xml>=1.3.14
BUILDLINK_ABI_DEPENDS.hs-xml+=	hs-xml>=1.3.14
BUILDLINK_PKGSRCDIR.hs-xml?=	../../textproc/hs-xml

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_XML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xml
