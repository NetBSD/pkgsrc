# $NetBSD: Makefile,v 1.1 2014/01/17 13:00:00 obache Exp $
#

DISTNAME=	thread_safe-0.1.3
CATEGORIES=	misc

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/headius/thread_safe
COMMENT=	Thread-safe collections and utilities for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-atomic>=0:../../devel/ruby-atomic

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
