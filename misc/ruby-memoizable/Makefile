# $NetBSD: Makefile,v 1.1 2014/01/17 13:01:09 obache Exp $
#

DISTNAME=	memoizable-0.4.0
CATEGORIES=	misc

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/dkubb/memoizable
COMMENT=	Memoize method return values
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.1.3:../../misc/ruby-thread_safe

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
