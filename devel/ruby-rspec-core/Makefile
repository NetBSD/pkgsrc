# $NetBSD: Makefile,v 1.43 2026/11/07 13:52:39 taca Exp $

DISTNAME=	rspec-core-3.13.7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby, core part
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.13.0<3.14:../../devel/ruby-rspec-support

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
