# $NetBSD: Makefile,v 1.3 2017/04/15 15:16:17 taca Exp $
#

DISTNAME=	thread_safe-0.3.6
CATEGORIES=	misc

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/headius/thread_safe
COMMENT=	Thread-safe collections and utilities for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-atomic>=0:../../devel/ruby-atomic

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
