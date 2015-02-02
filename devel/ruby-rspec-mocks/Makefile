# $NetBSD: Makefile,v 1.14 2015/02/02 14:22:28 taca Exp $

DISTNAME=	rspec-mocks-3.1.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://relishapp.com/rspec
COMMENT=	This is test-double framework for rspec
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec-support>=3.1.0<3.2:../../devel/ruby-rspec-support

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
