# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:06 joerg Exp $

BUILDLINK_TREE+=	metakit-lib

.if !defined(METAKIT_LIB_BUILDLINK3_MK)
METAKIT_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.metakit-lib+=	metakit-lib>=2.4.8
BUILDLINK_ABI_DEPENDS.metakit-lib+=	metakit-lib>=2.4.9.3nb1
BUILDLINK_PKGSRCDIR.metakit-lib?=	../../databases/metakit-lib
.endif # METAKIT_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-metakit-lib
