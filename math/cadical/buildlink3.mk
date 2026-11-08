# $NetBSD: buildlink3.mk,v 1.3 2026/11/08 13:51:53 alnsn Exp $

BUILDLINK_TREE+=	cadical

.if !defined(CADICAL_BUILDLINK3_MK)
CADICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cadical+=	cadical>=2.1.3<3
BUILDLINK_ABI_DEPENDS.cadical+=	cadical>=2.1.3nb1
BUILDLINK_PKGSRCDIR.cadical?=	../../math/cadical
.endif # CADICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cadical
