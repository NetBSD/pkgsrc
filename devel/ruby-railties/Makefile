# $NetBSD: Makefile,v 1.11 2013/02/06 16:04:23 taca Exp $

DISTNAME=	railties-${RUBY_RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 3.0
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14.6:../../devel/ruby-thor
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}

RUBY_RAILS_SUPPORTED=	3
RUBY_RAILS_STRICT_DEP=	yes
RUBY_RDOC_REQD=		3.4
OVERRIDE_GEMSPEC=	thor>=0.14.6

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
