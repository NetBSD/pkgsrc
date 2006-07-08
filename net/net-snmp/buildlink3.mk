# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:04 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NET_SNMP_BUILDLINK3_MK:=	${NET_SNMP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	net-snmp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnet-snmp}
BUILDLINK_PACKAGES+=	net-snmp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}net-snmp

.if !empty(NET_SNMP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.net-snmp+=	net-snmp>=5.0.9nb3
BUILDLINK_ABI_DEPENDS.net-snmp+=	net-snmp>=5.2.1.2
BUILDLINK_PKGSRCDIR.net-snmp?=	../../net/net-snmp
.endif	# NET_SNMP_BUILDLINK3_MK

.include "../../security/tcp_wrappers/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
