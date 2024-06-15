# $NetBSD: Makefile,v 1.38 2024/06/15 15:50:32 taca Exp $

DISTNAME=	rspec-expectations-3.13.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby, expectations
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.13.0<3.14:../../devel/ruby-rspec-support
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.0:../../textproc/ruby-diff-lcs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
