# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:25 joerg Exp $

BUILDLINK_TREE+=	libol

.if !defined(LIBOL_BUILDLINK3_MK)
LIBOL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libol+=	libol>=0.3.17
BUILDLINK_PKGSRCDIR.libol?=	../../sysutils/libol
.endif # LIBOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libol
