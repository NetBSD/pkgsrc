# $NetBSD: buildlink3.mk,v 1.6 2015/06/04 20:09:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-xml

.if !defined(HS_XML_BUILDLINK3_MK)
HS_XML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xml+=	hs-xml>=1.3.13
BUILDLINK_ABI_DEPENDS.hs-xml+=	hs-xml>=1.3.13nb5
BUILDLINK_PKGSRCDIR.hs-xml?=	../../textproc/hs-xml

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_XML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xml
