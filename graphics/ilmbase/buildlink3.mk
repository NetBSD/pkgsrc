# $NetBSD: buildlink3.mk,v 1.4 2011/01/03 17:58:35 wiz Exp $

BUILDLINK_TREE+=	ilmbase

.if !defined(ILMBASE_BUILDLINK3_MK)
ILMBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ilmbase+=	ilmbase>=1.0.1
BUILDLINK_PKGSRCDIR.ilmbase?=	../../graphics/ilmbase
.endif # ILMBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ilmbase
