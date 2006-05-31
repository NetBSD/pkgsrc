# $NetBSD: Makefile,v 1.1.1.1 2006/05/31 18:18:34 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
COMMENT=		Lightweight Directory Access Protocol libraries and client programs

CONFLICTS+=		openldap<2.3.23nb1

CONFIGURE_ARGS+=	--disable-slapd
CONFIGURE_ARGS+=	--disable-slurpd

#BUILD_DIRS=		include libraries clients

MAKE_DIRS=		${OPENLDAP_ETCDIR}

BUILD_DEFS+=		OPENLDAP_ETCDIR

CNFS=			ldap.conf

.include "../../databases/openldap/Makefile.common"
.include "../../mk/bsd.pkg.mk"
