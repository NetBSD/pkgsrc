# $NetBSD: Makefile,v 1.5 2012/04/29 05:28:41 taca Exp $

DISTNAME=	rspec-expectations-2.9.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby, expectations
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1.3<1.2:../../textproc/ruby-diff-lcs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
