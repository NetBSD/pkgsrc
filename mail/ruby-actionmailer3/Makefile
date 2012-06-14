# $NetBSD: Makefile,v 1.10 2012/06/14 14:51:27 taca Exp $

DISTNAME=	actionmailer-${RUBY_RAILS_VERSION}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery and receiving (for Rails 3.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.2.19<2.3:../../mail/ruby-mail22

RUBY_RAILS_SUPPORTED=	3
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
