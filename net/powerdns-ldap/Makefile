# $NetBSD: Makefile,v 1.15 2015/06/12 10:50:58 fhajny Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-ldap/}
PKGREVISION=		1
COMMENT=		LDAP backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="ldap"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
