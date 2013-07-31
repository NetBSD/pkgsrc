# $NetBSD: buildlink3.mk,v 1.6 2013/07/31 18:25:28 adam Exp $

BUILDLINK_TREE+=	ilmbase

.if !defined(ILMBASE_BUILDLINK3_MK)
ILMBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ilmbase+=	ilmbase>=1.0.1
BUILDLINK_ABI_DEPENDS.ilmbase+=	ilmbase>=2.0.0
BUILDLINK_PKGSRCDIR.ilmbase?=	../../graphics/ilmbase
.endif # ILMBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ilmbase
