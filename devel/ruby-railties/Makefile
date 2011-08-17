# $NetBSD: Makefile,v 1.7 2011/08/17 14:20:04 taca Exp $

DISTNAME=	railties-${RUBY_RAILS3_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails applications
LICENSE=	mit

RUBY_RAILS=	3
RUBY_RDOC_REQD=	3.4

DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14.4<0.15:../../devel/ruby-thor
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
