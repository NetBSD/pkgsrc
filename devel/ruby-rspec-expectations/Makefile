# $NetBSD: Makefile,v 1.12 2013/03/11 07:47:46 taca Exp $

DISTNAME=	rspec-expectations-2.13.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby, expectations
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1.3<2:../../textproc/ruby-diff-lcs

OVERRIDE_GEMSPEC+=	diff-lcs>=1.1.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
