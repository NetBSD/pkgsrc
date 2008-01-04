# $NetBSD: Makefile,v 1.2 2008/01/04 20:05:12 jmmv Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-ldap/}
PKGREVISION=		1
COMMENT=		LDAP backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="ldap"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
