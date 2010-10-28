# $NetBSD: Makefile,v 1.3 2010/10/28 02:58:51 obache Exp $

DISTNAME=	actionmailer-3.0.1
PKGREVISION=	1
CATEGORIES=	mail devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Email composition, delivery, and receiving framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=3.0.1:../../www/ruby-actionpack3
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.2.5:../../mail/ruby-mail

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
