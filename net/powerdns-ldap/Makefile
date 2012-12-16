# $NetBSD: Makefile,v 1.11 2012/12/16 01:52:30 obache Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-ldap/}
PKGREVISION=		3
COMMENT=		LDAP backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="ldap"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
