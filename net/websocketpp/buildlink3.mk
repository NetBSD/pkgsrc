# $NetBSD: buildlink3.mk,v 1.1 2017/03/14 13:09:37 wiz Exp $

BUILDLINK_TREE+=	websocketpp

.if !defined(WEBSOCKETPP_BUILDLINK3_MK)
WEBSOCKETPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.websocketpp+=	websocketpp>=0.7.0
BUILDLINK_PKGSRCDIR.websocketpp?=	../../net/websocketpp

# only headers
BUILDLINK_DEPMETHOD.websocketpp?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# WEBSOCKETPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-websocketpp
