# $NetBSD: Makefile,v 1.2 2020/03/21 23:51:41 joerg Exp $

DISTNAME=	actionmailbox-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actionmailbox${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Inbound email handling framework (for Rails 6.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIONVIEW_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEJOB_DEPENDS}

USE_LANGUAGES=	# none

RUBY_VERSIONS_INCOMPATIBLE=	24
RUBY_RAILS_ACCEPTED=	60
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
