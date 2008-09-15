# $NetBSD: Makefile,v 1.3 2008/09/15 09:01:41 taca Exp $

DISTNAME=	rubigen-1.3.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubigen.rubyforge.org/
COMMENT=	Ruby stub generator

BUILD_DEPENDS+=	hoe>=1.5.1:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.0.2nb1:../../devel/ruby-activesupport

#GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
