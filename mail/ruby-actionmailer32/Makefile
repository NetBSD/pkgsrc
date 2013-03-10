# $NetBSD: Makefile,v 1.4 2013/03/10 08:05:16 taca Exp $

DISTNAME=	actionmailer-${RUBY_RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving (for Rails 3.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail24>=2.4.4<2.5:../../mail/ruby-mail24

RUBY_RAILS_SUPPORTED=	32
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
