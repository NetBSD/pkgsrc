# $NetBSD: buildlink3.mk,v 1.2 2023/11/07 17:56:55 nros Exp $

BUILDLINK_TREE+=	ptex

.if !defined(PTEX_BUILDLINK3_MK)
PTEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ptex+=	ptex>=2.1.28
BUILDLINK_ABI_DEPENDS.ptex+=	ptex>=2.4.2
BUILDLINK_PKGSRCDIR.ptex?=	../../graphics/ptex

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# PTEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ptex
