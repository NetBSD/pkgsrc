# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	liblzo

.if !defined(LIBLZO_BUILDLINK3_MK)
LIBLZO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblzo+=	liblzo>=1.08
BUILDLINK_PKGSRCDIR.liblzo?=	../../archivers/liblzo
BUILDLINK_ABI_DEPENDS.liblzo+=	liblzo>=1.08nb1
.endif # LIBLZO_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblzo
