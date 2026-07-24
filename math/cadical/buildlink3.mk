# $NetBSD: buildlink3.mk,v 1.2 2026/07/24 18:36:40 wiz Exp $

BUILDLINK_TREE+=	cadical

.if !defined(CADICAL_BUILDLINK3_MK)
CADICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cadical+=	cadical>=2.1.3<3
BUILDLINK_ABI_DEPENDS.cadical+=	cadical>=2.1.3
BUILDLINK_PKGSRCDIR.cadical?=	../../math/cadical
.endif # CADICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cadical
