# $NetBSD: Makefile,v 1.5 2013/03/19 16:17:50 taca Exp $

DISTNAME=	railties-${RUBY_RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 3.2
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
DEPENDS+=	${RUBY_PKGPREFIX}-thor<2.0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-rack-ssl>=1.3.2<1.4:../../www/ruby-rack-ssl
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}

RUBY_RAILS_SUPPORTED=	32
RUBY_RAILS_STRICT_DEP=	yes
RUBY_RDOC_REQD=		3.4
USE_RAKE=		RUN
OVERRIDE_GEMSPEC=	thor>=0.14.6

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
