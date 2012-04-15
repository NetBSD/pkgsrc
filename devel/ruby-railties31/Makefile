# $NetBSD: Makefile,v 1.2.2.1 2012/04/15 15:25:31 tron Exp $

DISTNAME=	railties-${RUBY_RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 3.1
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
# Keep this first, since it requires a more restrictive ruby-rack than the rest
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14.6<0.15:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-rack-ssl>=1.3.2<1.4:../../www/ruby-rack-ssl

RUBY_RAILS_SUPPORTED=	31
RUBY_RDOC_REQD=		3.4

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
