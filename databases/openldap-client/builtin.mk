# $NetBSD: builtin.mk,v 1.1 2008/10/12 20:49:19 ahoka Exp $

BUILTIN_PKG:=	openldap-client

PKGCONFIG_FILE.openldap-client=	/usr/include/ldap_features.h
PKGCONFIG_BASE.openldap-client=	/usr

BUILTIN_VERSION_SCRIPT.openldap-client= ${AWK} \
	'/\#define[ \t]*_?LDAP_VENDOR_VERSION_MAJOR[ \t]/ { major = $$3; } \
	/\#define[ \t]*_?LDAP_VENDOR_VERSION_MINOR[ \t]/ { minor = $$3; } \
	/\#define[ \t]*_?LDAP_VENDOR_VERSION_PATCH[ \t]/ { patch = $$3; } \
	END { if (major && minor && patch) print major "." minor "." patch; \
	else print ""; }'

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
