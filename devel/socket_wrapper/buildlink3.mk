# $NetBSD: buildlink3.mk,v 1.1 2025/09/06 18:29:02 riastradh Exp $

BUILDLINK_TREE+=	socket_wrapper

.if !defined(SOCKET_WRAPPER_BUILDLINK3_MK)

BUILDLINK_API_DEPENDS.socket_wrapper+=	socket_wrapper>=1.5.0
BUILDLINK_ABI_DEPENDS.socket_wrapper+=	socket_wrapper>=1.5.0
BUILDLINK_PKGSRCDIR.socket_wrapper=	../../devel/socket_wrapper

.endif

BUILDLINK_TREE+=	-socket_wrapper
