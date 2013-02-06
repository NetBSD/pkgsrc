# $NetBSD: Makefile,v 1.14 2013/02/06 23:21:04 jperkin Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	2
COMMENT=	Lightweight Directory Access Protocol libraries and client programs

CONFLICTS+=		openldap<2.3.23nb1

CONFIGURE_ARGS+=	--disable-slapd

#BUILD_DIRS=		include libraries clients
MAKE_DIRS=		${OPENLDAP_ETCDIR}
BUILD_DEFS+=		OPENLDAP_ETCDIR

CNFS=			ldap.conf

.include "options.mk"

.include "../../databases/openldap/Makefile.common"
.include "../../mk/bsd.pkg.mk"
