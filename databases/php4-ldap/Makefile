# $NetBSD: Makefile,v 1.2 2001/10/16 06:58:31 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		ldap
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for LDAP database access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../databases/openldap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
