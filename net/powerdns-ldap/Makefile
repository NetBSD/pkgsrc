# $NetBSD: Makefile,v 1.23 2021/10/21 07:46:36 wiz Exp $

PKGREVISION= 1
.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-ldap/}
COMMENT=		LDAP backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="ldap"

BUILDLINK_API_DEPENDS.mit-krb5+= mit-krb5>=1.11

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
