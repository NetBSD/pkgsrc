# $NetBSD: Makefile,v 1.34 2023/04/27 14:15:46 taca Exp $

DISTNAME=	rspec-core-3.12.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby, core part
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.12.0<3.13:../../devel/ruby-rspec-support

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
