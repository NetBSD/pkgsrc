# $NetBSD: buildlink2.mk,v 1.3 2002/10/09 12:19:28 wiz Exp $

.if !defined(OPENLDAP_BUILDLINK2_MK)
OPENLDAP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		openldap
BUILDLINK_DEPENDS.openldap?=	openldap-1.2.*
BUILDLINK_PKGSRCDIR.openldap?=	../../databases/openldap1

EVAL_PREFIX+=		BUILDLINK_PREFIX.openldap=openldap
BUILDLINK_PREFIX.openldap_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openldap=	include/disptmpl.h
BUILDLINK_FILES.openldap+=	include/lber.h
BUILDLINK_FILES.openldap+=	include/ldap.h
BUILDLINK_FILES.openldap+=	include/ldap_cdefs.h
BUILDLINK_FILES.openldap+=	include/srchpref.h
BUILDLINK_FILES.openldap+=	lib/liblber.*
BUILDLINK_FILES.openldap+=	lib/libldap.*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
.  include "../../databases/db/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	openldap-buildlink

openldap-buildlink: _BUILDLINK_USE

.endif	# OPENLDAP_BUILDLINK2_MK
