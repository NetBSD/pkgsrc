# $NetBSD: Makefile,v 1.4 2017/06/21 14:42:55 taca Exp $

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
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rack-ssl>=1.3.2 rdoc>=3.4 \
			:executables rails=rails42 :files bin/rails=bin/rails42

pre-configure:
	${TEST} -f ${WRKSRC}/bin/rails42 || \
		${MV} ${WRKSRC}/bin/rails ${WRKSRC}/bin/rails42
	${CHMOD} ${BINMODE} ${WRKSRC}/bin/rails42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
