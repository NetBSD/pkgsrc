# $NetBSD: Makefile,v 1.2.4.1 2011/02/14 19:08:02 spz Exp $

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
