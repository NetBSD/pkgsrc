# $NetBSD: buildlink.mk,v 1.2 2002/04/20 18:46:06 fredb Exp $
#
# This Makefile fragment is included by packages that use libraries from
# ucd-snmp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.ucd-snmp to the dependency pattern
#     for the version of ucd-snmp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(UCD_SNMP_BUILDLINK_MK)
UCD_SNMP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.ucd-snmp?=		ucd-snmp-4.2.4*
DEPENDS+=	${BUILDLINK_DEPENDS.ucd-snmp}:../../net/ucd-snmp

EVAL_PREFIX+=			BUILDLINK_PREFIX.ucd-snmp=ucd-snmp
BUILDLINK_PREFIX.ucd-snmp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ucd-snmp=		include/ucd-snmp/*
BUILDLINK_FILES.ucd-snmp+=		lib/libsnmp*
BUILDLINK_FILES.ucd-snmp+=		lib/libucdagent*
BUILDLINK_FILES.ucd-snmp+=		lib/libucdmibs*

BUILDLINK_TARGETS.ucd-snmp=	ucd-snmp-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.ucd-snmp}

pre-configure: ${BUILDLINK_TARGETS.ucd-snmp}
ucd-snmp-buildlink: _BUILDLINK_USE

.endif	# UCD_SNMP_BUILDLINK_MK
