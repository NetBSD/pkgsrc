# $NetBSD: buildlink3.mk,v 1.1 2026/07/02 19:15:03 alnsn Exp $

BUILDLINK_TREE+=	cadical

.if !defined(CADICAL_BUILDLINK3_MK)
CADICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cadical+=	cadical>=2.1.3
BUILDLINK_ABI_DEPENDS.cadical+=	cadical>=2.1.3
BUILDLINK_PKGSRCDIR.cadical?=	../../math/cadical
.endif # CADICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cadical
