# $NetBSD: Makefile,v 1.42 2025/05/17 07:33:56 taca Exp $

DISTNAME=	rspec-mocks-3.13.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://relishapp.com/rspec
COMMENT=	This is test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.13.0<3.14:../../devel/ruby-rspec-support
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.0:../../textproc/ruby-diff-lcs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
