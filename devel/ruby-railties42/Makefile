# $NetBSD: Makefile,v 1.5 2018/03/13 16:37:13 taca Exp $

DISTNAME=	railties-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-railties${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 4.2
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.18.1<2.0:../../devel/ruby-thor

RUBY_RAILS_SUPPORTED=	42
RUBY_RAILS_STRICT_DEP=	yes
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	:executables rails=rails${RUBY_RAILS} \
			:files bin/rails=bin/rails${RUBY_RAILS}

pre-configure:
	${TEST} -f ${WRKSRC}/bin/rails${RUBY_RAILS} || \
		${MV} ${WRKSRC}/bin/rails ${WRKSRC}/bin/rails${RUBY_RAILS}
	${CHMOD} ${BINMODE} ${WRKSRC}/bin/rails${RUBY_RAILS}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
