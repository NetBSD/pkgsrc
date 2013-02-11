# $NetBSD: Makefile,v 1.11 2013/02/11 02:30:49 taca Exp $

DISTNAME=	rspec-expectations-2.12.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby, expectations
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1.3<2:../../textproc/ruby-diff-lcs

OVERRIDE_GEMSPEC+=	diff-lcs>=1.1.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
