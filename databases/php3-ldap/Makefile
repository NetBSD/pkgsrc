# $NetBSD: Makefile,v 1.1.1.1 2002/01/10 13:03:15 jlam Exp $

MODNAME=		ldap
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP3 extension for LDAP database access

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.module"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_DIR}
MOD_LIBS+=		-lldap -llber

.include "../../databases/openldap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
