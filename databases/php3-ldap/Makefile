# $NetBSD: Makefile,v 1.2 2002/10/09 11:55:53 wiz Exp $

MODNAME=		ldap
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP3 extension for LDAP database access

USE_BUILDLINK2=		yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
MOD_LIBS+=		-lldap -llber

.include "../../databases/openldap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
