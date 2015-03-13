# $NetBSD: Makefile,v 1.2 2015/03/13 14:53:30 taca Exp $
#

DISTNAME=	memoizable-0.4.2
CATEGORIES=	misc

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/dkubb/memoizable
COMMENT=	Memoize method return values
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.3.1:../../misc/ruby-thread_safe

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
