# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/10/24 08:29:33 jlam Exp $

.if !defined(NET_SNMP_BUILDLINK2_MK)
NET_SNMP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		net-snmp
BUILDLINK_PKGBASE.net-snmp=	net-snmp
BUILDLINK_DEPENDS.net-snmp?=	net-snmp>=5.0.6
BUILDLINK_PKGSRCDIR.net-snmp?=	../../net/net-snmp

EVAL_PREFIX+=				BUILDLINK_PREFIX.net-snmp=net-snmp
BUILDLINK_PREFIX.net-snmp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.net-snmp=		include/net-snmp/*/*
BUILDLINK_FILES.net-snmp=		include/net-snmp/*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmp.*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmpagent.*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmphelpers.*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmpmibs.*

BUILDLINK_TARGETS+=	net-snmp-buildlink

net-snmp-buildlink: _BUILDLINK_USE

.endif	# NET_SNMP_BUILDLINK2_MK
