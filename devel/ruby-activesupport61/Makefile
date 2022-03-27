# $NetBSD: Makefile,v 1.2 2022/03/27 06:29:57 wiz Exp $

DISTNAME=	activesupport-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activesupport${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit of support libraries (part of Rails 6.1)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1.6:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=2.0<3:../../time/ruby-tzinfo
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby
DEPENDS+=	${RUBY_PKGPREFIX}-zeitwerk>=2.2<3:../../devel/ruby-zeitwerk
# minitest 5.4.3 is bundlerd with Ruby 2.2 and later.
#DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=5.1<6:../../devel/ruby-minitest

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	61
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
