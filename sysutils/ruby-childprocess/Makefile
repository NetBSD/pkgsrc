# $NetBSD: Makefile,v 1.12 2018/03/21 15:15:13 taca Exp $

DISTNAME=	childprocess-0.8.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	ruby sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jarib/childprocess
COMMENT=	Simple and reliable solution for controlling external programs
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.0.11:../../devel/ruby-ffi

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
