# $NetBSD: buildlink3.mk,v 1.3 2011/01/03 08:47:54 dsainty Exp $

BUILDLINK_TREE+=	ilmbase

.if !defined(ILMBASE_BUILDLINK3_MK)
ILMBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ilmbase+=	ilmbase>=1.0.2nb1
BUILDLINK_PKGSRCDIR.ilmbase?=	../../graphics/ilmbase
.endif # ILMBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ilmbase
