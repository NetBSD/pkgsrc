# $NetBSD: Makefile,v 1.11 2004/03/26 02:27:36 wiz Exp $

MODNAME=		ldap
PKGREVISION=		2
CATEGORIES+=		databases
COMMENT=		PHP4 extension for LDAP database access

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../databases/openldap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
