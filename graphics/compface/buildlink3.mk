# $NetBSD: buildlink3.mk,v 1.11 2022/06/28 11:34:00 wiz Exp $

BUILDLINK_TREE+=	compface

.if !defined(COMPFACE_BUILDLINK3_MK)
COMPFACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compface+=	compface>=1.4
BUILDLINK_ABI_DEPENDS.compface+=	compface>=1.5.2nb11
BUILDLINK_PKGSRCDIR.compface?=		../../graphics/compface
.endif # COMPFACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-compface
