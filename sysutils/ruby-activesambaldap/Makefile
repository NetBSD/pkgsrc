# $NetBSD: Makefile,v 1.4 2015/09/26 23:39:58 taca Exp $

DISTNAME=	activesambaldap-0.1.0
CATEGORIES=	sysutils

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/activeldap/activesambaldap
COMMENT=	Library and management tools for Samba + LDAP environment
LICENSE=	gnu-lgpl-v2.1 OR gnu-lgpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-activeldap>=1.0.1:../../databases/ruby-activeldap

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
