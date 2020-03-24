# $NetBSD: Makefile,v 1.11 2020/03/24 15:48:52 taca Exp $

DISTNAME=	bcrypt-3.1.13
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codahale/bcrypt-ruby
COMMENT=	OpenBSD's bcrypt() password hashing algorithm for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
