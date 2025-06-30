# $NetBSD: Makefile,v 1.27 2025/06/30 11:02:21 jperkin Exp $

.include "../../net/powerdns/backend.mk"

PKGNAME=		${DISTNAME:S/pdns/powerdns-ldap/}
COMMENT=		LDAP backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="ldap"

BUILDLINK_API_DEPENDS.mit-krb5+=	mit-krb5>=1.11

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
