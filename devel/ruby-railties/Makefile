# $NetBSD: Makefile,v 1.5.2.1 2011/08/23 09:12:11 tron Exp $

DISTNAME=	railties-${RUBY_RAILS3_VERSION}
PKGREVISION=	1
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
