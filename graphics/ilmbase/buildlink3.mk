# $NetBSD: buildlink3.mk,v 1.5 2013/05/09 07:39:09 adam Exp $

BUILDLINK_TREE+=	ilmbase

.if !defined(ILMBASE_BUILDLINK3_MK)
ILMBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ilmbase+=	ilmbase>=1.0.1
BUILDLINK_ABI_DEPENDS.ilmbase?=	ilmbase>=2.0.0
BUILDLINK_PKGSRCDIR.ilmbase?=	../../graphics/ilmbase
.endif # ILMBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ilmbase
