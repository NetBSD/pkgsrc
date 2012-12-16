# $NetBSD: buildlink3.mk,v 1.13 2012/12/16 01:52:02 obache Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	openldap-client

.if !defined(OPENLDAP_BUILDLINK3_MK)
OPENLDAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openldap-client+=	openldap-client>=2.4.6
BUILDLINK_ABI_DEPENDS.openldap-client+=	openldap-client>=2.4.33nb1
BUILDLINK_PKGSRCDIR.openldap-client?=	../../databases/openldap-client

# Export the deprecated API from the openldap-2.2.x releases.
BUILDLINK_CPPFLAGS.openldap-client+=	-DLDAP_DEPRECATED

pkgbase := openldap-client
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.openldap-client:Mkerberos) || \
    !empty(PKG_BUILD_OPTIONS.openldap-client:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"
.endif # OPENLDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openldap-client
