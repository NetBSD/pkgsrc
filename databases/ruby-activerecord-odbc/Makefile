# $NetBSD: Makefile,v 1.15 2026/02/03 16:04:38 taca Exp $

DISTNAME=	activerecord-odbc-adapter-2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-adapter//}
PKGREVISION=	4
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://odbc-rails.rubyforge.org/
COMMENT=	ActiveRecord ODBC adapter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-odbc>=0.9991:../../databases/ruby-odbc
DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

USE_LANGUAGES=	# none

RUBY_ALLOW_HAS_RDOC=	# empty
RUBY_RAILS_ACCEPTED=	# empty
OVERRIDE_GEMSPEC=	:files lib/connection_adapters=

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
