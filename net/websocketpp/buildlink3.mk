# $NetBSD: buildlink3.mk,v 1.2 2025/09/27 09:57:34 wiz Exp $

BUILDLINK_TREE+=	websocketpp

.if !defined(WEBSOCKETPP_BUILDLINK3_MK)
WEBSOCKETPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.websocketpp+=	websocketpp>=0.7.0
BUILDLINK_ABI_DEPENDS.websocketpp?=	websocketpp>=0.8.2nb1
BUILDLINK_PKGSRCDIR.websocketpp?=	../../net/websocketpp

# only headers
BUILDLINK_DEPMETHOD.websocketpp?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# WEBSOCKETPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-websocketpp
