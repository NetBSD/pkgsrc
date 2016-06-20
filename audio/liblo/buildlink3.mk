# $NetBSD: buildlink3.mk,v 1.1 2016/06/20 08:09:40 kamil Exp $

BUILDLINK_TREE+=	liblo

.if !defined(LIBLO_BUILDLINK3_MK)
LIBLO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblo+=	liblo>=0.23
BUILDLINK_PKGSRCDIR.liblo?=	../../wip/liblo

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBLO_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblo
