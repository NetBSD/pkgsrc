# $NetBSD: Makefile,v 1.44 2025/07/27 16:04:28 taca Exp $

DISTNAME=	rspec-mocks-3.13.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rspec/rspec-mocks
COMMENT=	This is test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.13.0<3.14:../../devel/ruby-rspec-support
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.2.0:../../textproc/ruby-diff-lcs

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
