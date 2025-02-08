# $NetBSD: Makefile,v 1.9 2025/02/08 03:49:22 taca Exp $

DISTNAME=	Net_LDAP2-2.2.0
PKGREVISION=	1
CATEGORIES+=	net

MAINTAINER=	wenheping@gmail.com
COMMENT=	Object oriented interface for searching and manipulating LDAP-entries
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=${PHP_BASE_VERS}:../../databases/php-ldap

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
