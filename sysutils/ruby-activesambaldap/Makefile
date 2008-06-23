# $NetBSD: Makefile,v 1.1.1.1 2008/06/23 02:00:57 taca Exp $

DISTNAME=	activesambaldap-0.0.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/asl/
COMMENT=	Library and management tools for Samba + LDAP environment

DEPENDS+=	${RUBY_PKGPREFIX}-activeldap>=1.0.1:../../databases/ruby-activeldap

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
