# $NetBSD: Makefile,v 1.3.2.1 2011/02/14 19:08:02 spz Exp $

DISTNAME=	actionmailer-3.0.4
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=3.0.4<3.0.5:../../www/ruby-actionpack3
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.2.15<2.3:../../mail/ruby-mail

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
