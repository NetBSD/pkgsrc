# $NetBSD: Makefile,v 1.4 2022/07/13 14:46:24 taca Exp $

DISTNAME=	railties-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-railties${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 6.1
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0<2:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-method_source-[0-9]*:../../misc/ruby-method_source

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	61
RUBY_RAILS_STRICT_DEP=	yes
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	:executables rails=rails${RUBY_RAILS} \
			:files exe/rails=exe/rails${RUBY_RAILS}

pre-configure:
	${TEST} -f ${WRKSRC}/exe/rails${RUBY_RAILS} || \
		${MV} ${WRKSRC}/exe/rails ${WRKSRC}/exe/rails${RUBY_RAILS}
	${CHMOD} ${BINMODE} ${WRKSRC}/exe/rails${RUBY_RAILS}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
