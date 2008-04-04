# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:16:28 jlam Exp $

DISTNAME=	rubigen-1.2.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubigen.rubyforge.org/
COMMENT=	Ruby stub generator

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.0.2nb1:../../devel/ruby-activesupport

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
