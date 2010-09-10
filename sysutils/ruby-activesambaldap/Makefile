# $NetBSD: Makefile,v 1.2 2010/09/10 07:53:14 taca Exp $

DISTNAME=	activesambaldap-0.0.8
CATEGORIES=	sysutils

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/asl/
COMMENT=	Library and management tools for Samba + LDAP environment
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-activeldap>=1.0.1:../../databases/ruby-activeldap

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
