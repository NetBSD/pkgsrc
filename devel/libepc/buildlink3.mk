# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/01 20:41:40 wiz Exp $

BUILDLINK_TREE+=	libepc

.if !defined(LIBEPC_BUILDLINK3_MK)
LIBEPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepc+=	libepc>=0.3.11
BUILDLINK_PKGSRCDIR.libepc?=	../../devel/libepc

.include "../../net/libsoup24/buildlink3.mk"
.endif	# LIBEPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepc
