# $NetBSD: Makefile,v 1.3 2025/01/23 08:02:12 wiz Exp $

DISTNAME=	activesupport-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activesupport${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit of support libraries (part of Rails 8.0)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1.6<2:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=2.0<3:../../time/ruby-tzinfo
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.3.1<2:../../devel/ruby-concurrent-ruby
DEPENDS+=	${RUBY_PKGPREFIX}-connection_pool>=2.2.5:../../net/ruby-connection_pool

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	80
RUBY_RAILS_STRICT_DEP=	yes

RUBY_VERSIONS_INCOMPATIBLE=	31

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-benchmark>=0.3:../../benchmarks/ruby-benchmark
DEPENDS+=	${RUBY_PKGPREFIX}-securerandom>=0.3:../../security/ruby-securerandom
DEPENDS+=	${RUBY_PKGPREFIX}-uri>=0.13.1:../../www/ruby-uri

.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
