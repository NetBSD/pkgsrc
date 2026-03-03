# $NetBSD: buildlink3.mk,v 1.33 2026/03/03 02:34:19 gutteridge Exp $

BUILDLINK_TREE+=	girara

.if !defined(GIRARA_BUILDLINK3_MK)
GIRARA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.girara+=	girara>=0.2.8
BUILDLINK_ABI_DEPENDS.girara+=	girara>=2026.02.04
BUILDLINK_PKGSRCDIR.girara?=	../../graphics/girara

.endif # GIRARA_BUILDLINK3_MK

BUILDLINK_TREE+=	-girara
