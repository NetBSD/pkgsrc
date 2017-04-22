# $NetBSD: Makefile,v 1.1 2017/04/22 00:41:20 minskim Exp $

DISTNAME=	actionmailer-${RUBY_RAILS_VERSION}
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving (for Rails 4.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIONVIEW_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail25>=2.5.4<2.6:../../mail/ruby-mail25
DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing>=1.0.5:../../textproc/ruby-rails-dom-testing

RUBY_RAILS_SUPPORTED=	42
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
