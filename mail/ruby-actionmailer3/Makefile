# $NetBSD: Makefile,v 1.5 2011/03/23 14:50:15 taca Exp $

DISTNAME=	actionmailer-${RUBY_RAILS3_VERSION}
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving framework
LICENSE=	mit

RUBY_RAILS=	3

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.2.15<2.3:../../mail/ruby-mail

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
