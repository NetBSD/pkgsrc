# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:35 jlam Exp $
#
# This Makefile fragment is included by packages that use openldap.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.openldap to the dependency pattern
#     for the version of openldap desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(OPENLDAP_BUILDLINK2_MK)
OPENLDAP_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.openldap?=	openldap-2.0.*
DEPENDS+=	${BUILDLINK_DEPENDS.openldap}:../../databases/openldap

EVAL_PREFIX+=	BUILDLINK_PREFIX.openldap=openldap
BUILDLINK_PREFIX.openldap_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openldap=	include/disptmpl.h
BUILDLINK_FILES.openldap+=	include/lber.h
BUILDLINK_FILES.openldap+=	include/lber_types.h
BUILDLINK_FILES.openldap+=	include/ldap.h
BUILDLINK_FILES.openldap+=	include/ldap_cdefs.h
BUILDLINK_FILES.openldap+=	include/ldap_features.h
BUILDLINK_FILES.openldap+=	include/ldap_schema.h
BUILDLINK_FILES.openldap+=	include/srchpref.h
BUILDLINK_FILES.openldap+=	lib/liblber.*
BUILDLINK_FILES.openldap+=	lib/libldap.*

USE_PTHREAD=		native

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
.  include "../../databases/db/buildlink2.mk"
.endif

.include "../../mk/pthread.buildlink2.mk"

.if defined(USE_SASL) && (${USE_SASL} == "YES")
.  include "../../security/cyrus-sasl/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	openldap-buildlink

openldap-buildlink: _BUILDLINK_USE

.endif	# OPENLDAP_BUILDLINK2_MK
