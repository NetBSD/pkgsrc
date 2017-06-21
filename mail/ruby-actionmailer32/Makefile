# $NetBSD: Makefile,v 1.9 2017/06/21 13:12:20 taca Exp $

DISTNAME=	actionmailer-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-actionmailer${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving (for Rails 3.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail25>=2.5.4<2.6:../../mail/ruby-mail25

RUBY_RAILS_SUPPORTED=	32
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
