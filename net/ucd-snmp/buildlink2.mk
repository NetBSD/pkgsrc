# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:39 jlam Exp $

.if !defined(UCD_SNMP_BUILDLINK2_MK)
UCD_SNMP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ucd-snmp
BUILDLINK_DEPENDS.ucd-snmp?=		ucd-snmp-4.2.4*
BUILDLINK_PKGSRCDIR.ucd-snmp?=		../../net/ucd-snmp

EVAL_PREFIX+=				BUILDLINK_PREFIX.ucd-snmp=ucd-snmp
BUILDLINK_PREFIX.ucd-snmp_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.ucd-snmp=	include/ucd-snmp/*
BUILDLINK_FILES.ucd-snmp+=	lib/libsnmp*
BUILDLINK_FILES.ucd-snmp+=	lib/libucdagent*
BUILDLINK_FILES.ucd-snmp+=	lib/libucdmibs*

BUILDLINK_TARGETS+=	ucd-snmp-buildlink

ucd-snmp-buildlink: _BUILDLINK_USE

.endif	# UCD_SNMP_BUILDLINK2_MK
