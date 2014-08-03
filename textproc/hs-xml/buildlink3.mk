# $NetBSD: buildlink3.mk,v 1.1 2014/08/03 21:28:58 szptvlfn Exp $

BUILDLINK_TREE+=	hs-xml

.if !defined(HS_XML_BUILDLINK3_MK)
HS_XML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-xml+=	hs-xml>=1.3.13
BUILDLINK_PKGSRCDIR.hs-xml?=	../../textproc/hs-xml

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_XML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-xml
