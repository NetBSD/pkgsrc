# $NetBSD: Makefile,v 1.23 2017/09/04 18:08:23 wiz Exp $

DISTNAME=	rspec-mocks-3.6.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://relishapp.com/rspec
COMMENT=	This is test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.6.0<3.7:../../devel/ruby-rspec-support
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs<2:../../textproc/ruby-diff-lcs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
