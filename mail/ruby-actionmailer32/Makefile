# $NetBSD: Makefile,v 1.2 2012/06/02 01:41:47 taca Exp $

DISTNAME=	actionmailer-${RUBY_RAILS_VERSION}
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving (for Rails 3.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.4.4<2.5:../../mail/ruby-mail

RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
