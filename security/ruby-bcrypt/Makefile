# $NetBSD: Makefile,v 1.12 2020/09/14 14:02:14 taca Exp $

DISTNAME=	bcrypt-3.1.16
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codahale/bcrypt-ruby
COMMENT=	OpenBSD's bcrypt() password hashing algorithm for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
