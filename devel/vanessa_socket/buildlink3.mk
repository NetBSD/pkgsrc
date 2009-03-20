# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:31 joerg Exp $
#
# This file was created automatically using createbuildlink-3.5.

BUILDLINK_TREE+=	vanessa_socket

.if !defined(VANESSA_SOCKET_BUILDLINK3_MK)
VANESSA_SOCKET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vanessa_socket+=	vanessa_socket>=0.0.7nb2
BUILDLINK_ABI_DEPENDS.vanessa_socket?=	vanessa_socket>=0.0.7nb3
BUILDLINK_PKGSRCDIR.vanessa_socket?=	../../devel/vanessa_socket

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
.endif # VANESSA_SOCKET_BUILDLINK3_MK

BUILDLINK_TREE+=	-vanessa_socket
