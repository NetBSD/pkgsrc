# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:23:53 joerg Exp $

BUILDLINK_TREE+=	id3lib

.if !defined(ID3LIB_BUILDLINK3_MK)
ID3LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.id3lib+=	id3lib>=3.8.3
BUILDLINK_ABI_DEPENDS.id3lib+=	id3lib>=3.8.3nb1
BUILDLINK_PKGSRCDIR.id3lib?=	../../audio/id3lib

.include "../../devel/zlib/buildlink3.mk"
.endif # ID3LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-id3lib
