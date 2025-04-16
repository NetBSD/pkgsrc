# $NetBSD: Makefile,v 1.4 2025/04/16 15:23:06 taca Exp $

DISTNAME=	observer-0.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/observer
COMMENT=	Implementation of the Observer object-oriented design pattern
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.3.8 and Ruby 3.4.3 have observer 0.1.2 gem.
RUBY_VERSIONS_ACCEPTED=	31 32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
