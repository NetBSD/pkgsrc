# $NetBSD: buildlink.mk,v 1.4 2002/01/31 05:06:55 jlam Exp $
#
# This Makefile fragment is included by packages that use openldap.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.openldap to the dependency pattern
#     for the version of openldap desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(OPENLDAP_BUILDLINK_MK)
OPENLDAP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.openldap?=	openldap-2.0.*
DEPENDS+=	${BUILDLINK_DEPENDS.openldap}:../../databases/openldap

EVAL_PREFIX+=		BUILDLINK_PREFIX.openldap=openldap
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
.include "../../databases/db/buildlink.mk"
.endif

.include "../../mk/pthread.buildlink.mk"

BUILDLINK_TARGETS.openldap=	openldap-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.openldap}

pre-configure: ${BUILDLINK_TARGETS.openldap}
openldap-buildlink: _BUILDLINK_USE

.endif	# OPENLDAP_BUILDLINK_MK
