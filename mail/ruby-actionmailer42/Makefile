# $NetBSD: Makefile,v 1.3 2017/09/18 06:47:04 taca Exp $

DISTNAME=	actionmailer-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actionmailer${RUBY_RAILS}-${RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving (for Rails 4.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIONVIEW_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.5.4:../../mail/ruby-mail
# ruby-actionview already depends it.
#DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing>=1.0.5:../../textproc/ruby-rails-dom-testing

RUBY_RAILS_SUPPORTED=	42
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
