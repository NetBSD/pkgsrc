# $NetBSD: buildlink.mk,v 1.2 2002/04/05 07:57:16 tron Exp $
#
# This Makefile fragment is included by packages that use libraries from
# net-snmp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.net-snmp to the dependency pattern
#     for the version of net-snmp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(NET_SNMP_BUILDLINK_MK)
NET_SNMP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.net-snmp?=		net-snmp>=5.0.0.2
DEPENDS+=	${BUILDLINK_DEPENDS.net-snmp}:../../net/net-snmp

EVAL_PREFIX+=			BUILDLINK_PREFIX.net-snmp=net-snmp
BUILDLINK_PREFIX.net-snmp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.net-snmp=		include/net-snmp/*
BUILDLINK_FILES.net-snmp=		include/ucd-snmp/*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmp*

BUILDLINK_TARGETS.net-snmp=	net-snmp-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.net-snmp}

pre-configure: ${BUILDLINK_TARGETS.net-snmp}
net-snmp-buildlink: _BUILDLINK_USE

.endif	# NET_SNMP_BUILDLINK_MK
