# $NetBSD: Makefile,v 1.6 2014/07/19 02:50:41 wen Exp $

DISTNAME=	Net_LDAP2-2.1.0
CATEGORIES+=	net

MAINTAINER=	wenheping@gmail.com
COMMENT=	Object oriented interface for searching and manipulating LDAP-entries
LICENSE=	gnu-lgpl-v3

DEPENDS+=      ${PHP_PKG_PREFIX}-ldap>=5.2.12:../../databases/php-ldap

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
