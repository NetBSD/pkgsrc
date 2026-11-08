# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 14:57:45 ryoon Exp $

BUILDLINK_TREE+=	alembic

.if !defined(ALEMBIC_BUILDLINK3_MK)
ALEMBIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alembic+=	alembic>=1.8.12
BUILDLINK_PKGSRCDIR.alembic?=	../../graphics/alembic

.include "../../math/imath/buildlink3.mk"
.endif	# ALEMBIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-alembic
