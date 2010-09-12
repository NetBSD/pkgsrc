# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 04:21:29 taca Exp $

DISTNAME=	railties-3.0.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14.0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.0:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=3.0.0:../../www/ruby-actionpack3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
