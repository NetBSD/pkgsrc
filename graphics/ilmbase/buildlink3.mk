# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:40 joerg Exp $

BUILDLINK_TREE+=	ilmbase

.if !defined(ILMBASE_BUILDLINK3_MK)
ILMBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ilmbase+=	ilmbase>=1.0.1
BUILDLINK_PKGSRCDIR.ilmbase?=	../../graphics/ilmbase
.endif # ILMBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ilmbase
