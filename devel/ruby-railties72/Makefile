# $NetBSD: Makefile,v 1.2 2025/01/03 02:35:40 taca Exp $

DISTNAME=	railties-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-railties${RUBY_RAILS}-${RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 7.2
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-rackup>=1.0.0:../../www/ruby-rackup
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0<2:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-zeitwerk>=2.6<3:../../devel/ruby-zeitwerk

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	72
RUBY_RAILS_STRICT_DEP=	yes
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	:executables rails=rails${RUBY_RAILS} \
			:files exe/rails=exe/rails${RUBY_RAILS}

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-irb>=1.13<2:../../devel/ruby-irb
.endif

pre-configure:
	${TEST} -f ${WRKSRC}/exe/rails${RUBY_RAILS} || \
		${MV} ${WRKSRC}/exe/rails ${WRKSRC}/exe/rails${RUBY_RAILS}
	${CHMOD} ${BINMODE} ${WRKSRC}/exe/rails${RUBY_RAILS}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
