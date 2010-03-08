# $NetBSD: Makefile,v 1.5 2010/03/08 12:51:45 fhajny Exp $

DISTNAME=	rubigen-1.5.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubigen.rubyforge.org/
COMMENT=	Ruby stub generator

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.5:../../devel/ruby-activesupport

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
