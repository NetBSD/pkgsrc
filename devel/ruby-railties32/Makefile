# $NetBSD: Makefile,v 1.14 2017/06/21 14:42:55 taca Exp $

DISTNAME=	railties-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-railties${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Tools for creating, working with, and running Rails 3.2
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
DEPENDS+=	${RUBY_PKGPREFIX}-thor<2.0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-rack-ssl>=1.3.2<1.5:../../www/ruby-rack-ssl
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}

RUBY_RAILS_SUPPORTED=	32
RUBY_RAILS_STRICT_DEP=	yes
RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rack-ssl>=1.3.2 rdoc>=3.4 \
			:executables rails=rails32 :files bin/rails=bin/rails32

pre-configure:
	${TEST} -f ${WRKSRC}/bin/rails32 || \
		${MV} ${WRKSRC}/bin/rails ${WRKSRC}/bin/rails32
	${CHMOD} ${BINMODE} ${WRKSRC}/bin/rails32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
