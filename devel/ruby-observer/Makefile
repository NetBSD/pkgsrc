# $NetBSD: Makefile,v 1.3 2025/01/19 13:42:25 taca Exp $

DISTNAME=	observer-0.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/observer
COMMENT=	Implementation of the Observer object-oriented design pattern
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.3.7 and Ruby 3.4.1 have observer 0.1.2 gem.
RUBY_VERSIONS_ACCEPTED=	31 32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
