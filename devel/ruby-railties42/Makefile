# $NetBSD: Makefile,v 1.2 2017/05/04 07:37:09 taca Exp $

DISTNAME=	railties-${RUBY_RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 4.2
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.18.1<2.0:../../devel/ruby-thor

RUBY_RAILS_SUPPORTED=	42
RUBY_RAILS_STRICT_DEP=	yes
USE_RAKE=		RUN
OVERRIDE_GEMSPEC+=	rack-ssl>=1.3.2 rdoc>=3.4

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
