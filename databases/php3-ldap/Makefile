# $NetBSD: Makefile,v 1.3 2003/05/02 11:54:14 wiz Exp $

MODNAME=		ldap
CATEGORIES+=		databases
PKGREVISION=		1
COMMENT=		PHP3 extension for LDAP database access

USE_BUILDLINK2=		yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
MOD_LIBS+=		-lldap -llber

.include "../../databases/openldap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
