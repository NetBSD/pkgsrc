# $NetBSD: buildlink3.mk,v 1.11 2011/04/15 16:23:00 drochner Exp $

BUILDLINK_TREE+=	liblzo

.if !defined(LIBLZO_BUILDLINK3_MK)
LIBLZO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblzo+=	liblzo>=1.08
BUILDLINK_PKGSRCDIR.liblzo?=	../../archivers/liblzo
BUILDLINK_ABI_DEPENDS.liblzo+=	liblzo>=1.08nb1
.endif # LIBLZO_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblzo
