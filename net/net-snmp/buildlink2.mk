# $NetBSD: buildlink2.mk,v 1.3 2002/10/24 09:54:43 jlam Exp $

.if !defined(NET_SNMP_BUILDLINK2_MK)
NET_SNMP_BUILDLINK2_MK=	# defined

# If a package uses the UCD-SNMP interface to Net-SNMP, then first check
# if ucd-snmp is installed.  If it is, then use it, otherwise, use the
# net-snmp package with the ucd-snmp-compatibility headers and libraries.
#
.if defined(USE_UCD_SNMP)
_UCD_SNMP_INSTALLED!=	${PKG_INFO} -e ucd-snmp || ${ECHO}
.  if !empty(_UCD_SNMP_INSTALLED)
.    include "../../net/ucd-snmp/buildlink2.mk"
.  else

BUILDLINK_PACKAGES+=		net-snmp
BUILDLINK_PKGBASE.net-snmp=	net-snmp
BUILDLINK_DEPENDS.net-snmp?=	net-snmp>=5.0.6
BUILDLINK_PKGSRCDIR.net-snmp?=	../../net/net-snmp

EVAL_PREFIX+=				BUILDLINK_PREFIX.net-snmp=net-snmp
BUILDLINK_PREFIX.net-snmp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.net-snmp=		include/net-snmp/*/*
BUILDLINK_FILES.net-snmp+=		include/net-snmp/*
BUILDLINK_FILES.net-snmp+=		include/ucd-snmp/*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmp.*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmpagent.*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmphelpers.*
BUILDLINK_FILES.net-snmp+=		lib/libnetsnmpmibs.*
BUILDLINK_FILES.net-snmp+=		lib/libsnmp.*

BUILDLINK_TARGETS+=	net-snmp-buildlink

net-snmp-buildlink: _BUILDLINK_USE

.  endif  # _UCD_SNMP_INSTALLED
.endif	  # USE_UCD_SNMP

.endif	# NET_SNMP_BUILDLINK2_MK
