# $NetBSD: Makefile,v 1.3 2012/09/16 11:13:08 taca Exp $

DISTNAME=	activesambaldap-0.1.0
CATEGORIES=	sysutils

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/asl/
COMMENT=	Library and management tools for Samba + LDAP environment
LICENSE=	gnu-lgpl-v2.1 OR gnu-lgpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-activeldap>=1.0.1:../../databases/ruby-activeldap

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
