# $NetBSD: Makefile,v 1.8 2006/05/31 18:22:23 ghen Exp $

MODNAME=		ldap
PKGREVISION=		4
CATEGORIES+=		databases
COMMENT=		PHP extension for LDAP database access

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap-client}

.include "../../lang/php/ext.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
