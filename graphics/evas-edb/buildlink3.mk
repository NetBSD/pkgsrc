# $NetBSD: buildlink3.mk,v 1.1 2013/06/16 18:56:04 sno Exp $

BUILDLINK_TREE+=	evas-edb

.if !defined(EVAS_EDB_BUILDLINK3_MK)
EVAS_EDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas-edb+=	evas-edb>=1.7.7
BUILDLINK_PKGSRCDIR.evas-edb?=	../../graphics/evas-edb

.include "../../databases/edb/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # EVAS_EDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas-edb
