# $NetBSD: buildlink2.mk,v 1.6 2003/09/18 05:37:15 markd Exp $

.if !defined(OPENLDAP_BUILDLINK2_MK)
OPENLDAP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		openldap
BUILDLINK_DEPENDS.openldap?=	openldap>=2.1.22
BUILDLINK_PKGSRCDIR.openldap?=	../../databases/openldap

EVAL_PREFIX+=	BUILDLINK_PREFIX.openldap=openldap
BUILDLINK_PREFIX.openldap_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openldap+=	include/lber.h
BUILDLINK_FILES.openldap+=	include/lber_types.h
BUILDLINK_FILES.openldap+=	include/ldap.h
BUILDLINK_FILES.openldap+=	include/ldap_cdefs.h
BUILDLINK_FILES.openldap+=	include/ldap_features.h
BUILDLINK_FILES.openldap+=	include/ldap_schema.h
BUILDLINK_FILES.openldap+=	include/ldap_utf8.h
BUILDLINK_FILES.openldap+=	lib/liblber.*
BUILDLINK_FILES.openldap+=	lib/libldap.*
BUILDLINK_FILES.openldap+=	lib/libldap_r.*

.include "../../mk/bsd.prefs.mk"

.if defined(USE_SASL2) && (${USE_SASL2} == "YES")
.  include "../../security/cyrus-sasl2/buildlink2.mk"
.elif defined(USE_SASL) && (${USE_SASL} == "YES")
.  include "../../security/cyrus-sasl/buildlink2.mk"
.endif

.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	openldap-buildlink

openldap-buildlink: _BUILDLINK_USE

.endif	# OPENLDAP_BUILDLINK2_MK
