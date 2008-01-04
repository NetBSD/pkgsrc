# $NetBSD: Makefile,v 1.5 2008/01/04 11:42:30 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
COMMENT=		Lightweight Directory Access Protocol libraries and client programs

CONFLICTS+=		openldap<2.3.23nb1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--disable-slapd
CONFIGURE_ARGS+=	--disable-slurpd

#BUILD_DIRS=		include libraries clients

MAKE_DIRS=		${OPENLDAP_ETCDIR}

BUILD_DEFS+=		OPENLDAP_ETCDIR

CNFS=			ldap.conf

.include "options.mk"

.include "../../databases/openldap/Makefile.common"
.include "../../mk/bsd.pkg.mk"
