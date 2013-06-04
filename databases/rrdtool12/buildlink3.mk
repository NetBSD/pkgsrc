# $NetBSD: buildlink3.mk,v 1.10 2013/06/04 22:15:49 tron Exp $

BUILDLINK_TREE+=	rrdtool

.if !defined(RRDTOOL_BUILDLINK3_MK)
RRDTOOL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rrdtool+=	rrdtool>=1.2.29
BUILDLINK_ABI_DEPENDS.rrdtool+=	rrdtool>=1.2.30nb10
BUILDLINK_PKGSRCDIR.rrdtool?=	../../databases/rrdtool

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.endif # RRDTOOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-rrdtool
