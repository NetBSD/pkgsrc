# $NetBSD: Makefile,v 1.3 2011/02/09 13:04:29 taca Exp $

DISTNAME=	railties-3.0.4
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14.4<0.15:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.4<3.0.5:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=3.0.4<3.0.5:../../www/ruby-actionpack3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
