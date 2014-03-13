# $NetBSD: Makefile,v 1.5 2014/03/13 11:08:52 jperkin Exp $

DISTNAME=	bcrypt-ruby-3.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-core
COMMENT=	OpenBSD's bcrypt() password hashing algorithm for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
