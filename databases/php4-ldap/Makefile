# $NetBSD: Makefile,v 1.8 2003/08/31 19:55:31 jdolecek Exp $

MODNAME=		ldap
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for LDAP database access

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${PKGDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.openldap}
CONFIGURE_ENV+=		PTHREAD_TYPE="${PTHREAD_TYPE}"

.include "../../databases/openldap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
