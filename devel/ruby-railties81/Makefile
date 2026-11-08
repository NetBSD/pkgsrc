# $NetBSD: Makefile,v 1.1 2026/11/08 16:12:28 taca Exp $

DISTNAME=	railties-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-railties${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 8.1
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rackup>=1.0.0:../../www/ruby-rackup
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.2.2<2:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-zeitwerk>=2.6<3:../../devel/ruby-zeitwerk

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	81
RUBY_RAILS_STRICT_DEP=	yes

RUBYGEM_OPTIONS+=	--format-executable
REPLACE_RUBY+=		${WRKSRC}/exe/rails${RUBY_RAILS}
OVERRIDE_GEMSPEC+=	:executables rails=rails${RUBY_RAILS} \
			:files exe/rails=exe/rails${RUBY_RAILS}

pre-configure:
	${TEST} -f ${WRKSRC}/exe/rails${RUBY_RAILS} || \
		${MV} ${WRKSRC}/exe/rails ${WRKSRC}/exe/rails${RUBY_RAILS}
	${CHMOD} ${BINMODE} ${WRKSRC}/exe/rails${RUBY_RAILS}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
