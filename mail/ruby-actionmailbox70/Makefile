# $NetBSD: Makefile,v 1.3 2022/03/27 06:43:11 wiz Exp $

DISTNAME=	actionmailbox-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actionmailbox${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Inbound email handling framework (for Rails 7.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESTORAGE_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.7.1:../../mail/ruby-mail

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	70
RUBY_RAILS_STRICT_DEP=	yes

RUBY_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
