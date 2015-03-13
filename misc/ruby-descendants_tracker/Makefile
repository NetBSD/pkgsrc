# $NetBSD: Makefile,v 1.2 2015/03/13 14:45:47 taca Exp $
#

DISTNAME=	descendants_tracker-0.0.4
CATEGORIES=	misc

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/dkubb/descendants_tracker
COMMENT=	Ruby Module that adds descendant tracking to a class
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.3.1:../../misc/ruby-thread_safe

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
