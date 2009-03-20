# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	lzo

.if !defined(LZO_BUILDLINK3_MK)
LZO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lzo+=		lzo>=2.01
BUILDLINK_PKGSRCDIR.lzo?=	../../archivers/lzo
.endif # LZO_BUILDLINK3_MK

BUILDLINK_TREE+=	-lzo
