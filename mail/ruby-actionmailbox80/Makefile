# $NetBSD: Makefile,v 1.2 2025/01/23 08:02:13 wiz Exp $

DISTNAME=	actionmailbox-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actionmailbox${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Inbound email handling framework (for Rails 8.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESTORAGE_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.8.0:../../mail/ruby-mail

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	80
RUBY_RAILS_STRICT_DEP=	yes

RUBY_VERSIONS_INCOMPATIBLE=	31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
