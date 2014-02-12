# $NetBSD: buildlink3.mk,v 1.2 2014/02/12 23:17:59 tron Exp $

BUILDLINK_TREE+=	evas-edb

.if !defined(EVAS_EDB_BUILDLINK3_MK)
EVAS_EDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-edb+=	evas-edb>=1.7.7
BUILDLINK_ABI_DEPENDS.evas-edb?=	evas-edb>=1.7.7nb1
BUILDLINK_PKGSRCDIR.evas-edb?=	../../graphics/evas-edb

.include "../../databases/edb/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # EVAS_EDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-edb
