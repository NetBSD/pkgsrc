# $NetBSD: Makefile,v 1.10 2018/09/23 16:05:28 taca Exp $

DISTNAME=	bcrypt-3.1.12
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-core
COMMENT=	OpenBSD's bcrypt() password hashing algorithm for Ruby
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
