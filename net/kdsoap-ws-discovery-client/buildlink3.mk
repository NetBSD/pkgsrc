# $NetBSD: buildlink3.mk,v 1.3 2026/02/06 10:05:33 wiz Exp $

BUILDLINK_TREE+=	kdsoap-ws-discovery-client

.if !defined(KDSOAP_WS_DISCOVERY_CLIENT_BUILDLINK3_MK)
KDSOAP_WS_DISCOVERY_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsoap-ws-discovery-client+=	kdsoap-ws-discovery-client>=0.4.0
BUILDLINK_ABI_DEPENDS.kdsoap-ws-discovery-client?=	kdsoap-ws-discovery-client>=0.4.0nb2
BUILDLINK_PKGSRCDIR.kdsoap-ws-discovery-client?=	../../net/kdsoap-ws-discovery-client

.include "../../net/kdsoap/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDSOAP_WS_DISCOVERY_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsoap-ws-discovery-client
