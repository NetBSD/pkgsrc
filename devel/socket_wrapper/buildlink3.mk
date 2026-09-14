# $NetBSD: buildlink3.mk,v 1.2 2026/09/14 22:11:00 wiz Exp $

BUILDLINK_TREE+=	socket_wrapper

.if !defined(SOCKET_WRAPPER_BUILDLINK3_MK)
SOCKET_WRAPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.socket_wrapper+=	socket_wrapper>=1.5.0
BUILDLINK_ABI_DEPENDS.socket_wrapper+=	socket_wrapper>=1.5.0
BUILDLINK_PKGSRCDIR.socket_wrapper=	../../devel/socket_wrapper

.endif

BUILDLINK_TREE+=	-socket_wrapper
