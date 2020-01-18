# $NetBSD: buildlink3.mk,v 1.20 2020/01/18 21:48:00 jperkin Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	openldap-client

.if !defined(OPENLDAP_BUILDLINK3_MK)
OPENLDAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openldap-client+=	openldap-client>=2.4.6
BUILDLINK_ABI_DEPENDS.openldap-client+=	openldap-client>=2.4.48nb1
BUILDLINK_PKGSRCDIR.openldap-client?=	../../databases/openldap-client

# Export the deprecated API from the openldap-2.2.x releases.
BUILDLINK_CPPFLAGS.openldap-client+=	-DLDAP_DEPRECATED

CHECK_BUILTIN.openldap-client:=	yes
.include "../../databases/openldap-client/builtin.mk"
CHECK_BUILTIN.openldap-client:=	no

.if empty(USE_BUILTIN.openldap-client:M[yY][eE][sS])
pkgbase := openldap-client
.  include "../../mk/pkg-build-options.mk"

.  if !empty(PKG_BUILD_OPTIONS.openldap-client:Mkerberos) || \
        !empty(PKG_BUILD_OPTIONS.openldap-client:Msasl)
.    include "../../security/cyrus-sasl/buildlink3.mk"
.  endif
.endif
.include "../../security/openssl/buildlink3.mk"
.endif # OPENLDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openldap-client
