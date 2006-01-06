# $NetBSD: Makefile,v 1.6 2006/01/06 15:10:02 wiz Exp $

MODNAME=		ldap
PKGREVISION=		2
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
