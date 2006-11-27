# $NetBSD: Makefile,v 1.3 2006/11/27 12:44:36 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
PKGREVISION=		1
COMMENT=		Lightweight Directory Access Protocol libraries and client programs

CONFLICTS+=		openldap<2.3.23nb1

CONFIGURE_ARGS+=	--disable-slapd
CONFIGURE_ARGS+=	--disable-slurpd

#BUILD_DIRS=		include libraries clients

MAKE_DIRS=		${OPENLDAP_ETCDIR}

BUILD_DEFS+=		OPENLDAP_ETCDIR

CNFS=			ldap.conf

.include "options.mk"

.include "../../databases/openldap/Makefile.common"
.include "../../mk/bsd.pkg.mk"
