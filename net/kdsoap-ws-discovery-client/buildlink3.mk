# $NetBSD: buildlink3.mk,v 1.1 2025/12/30 02:23:47 markd Exp $

BUILDLINK_TREE+=	kdsoap-ws-discovery-client

.if !defined(KDSOAP_WS_DISCOVERY_CLIENT_BUILDLINK3_MK)
KDSOAP_WS_DISCOVERY_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsoap-ws-discovery-client+=	kdsoap-ws-discovery-client>=0.4.0
BUILDLINK_PKGSRCDIR.kdsoap-ws-discovery-client?=	../../net/kdsoap-ws-discovery-client

.include "../../net/kdsoap/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDSOAP_WS_DISCOVERY_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsoap-ws-discovery-client
