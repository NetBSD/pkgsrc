# $NetBSD: Makefile,v 1.14 2015/03/13 13:45:35 taca Exp $

DISTNAME=	rspec-core-3.2.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	Behaviour Driven Development framework for Ruby, core part
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.2.0<3.3:../../devel/ruby-rspec-support

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
