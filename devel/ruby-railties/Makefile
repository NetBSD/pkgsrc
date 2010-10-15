# $NetBSD: Makefile,v 1.2 2010/10/15 11:45:22 taca Exp $

DISTNAME=	railties-3.0.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14.0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.1:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=3.0.1:../../www/ruby-actionpack3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
