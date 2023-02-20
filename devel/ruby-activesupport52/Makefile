# $NetBSD: Makefile,v 1.4 2023/02/20 13:30:42 taca Exp $

DISTNAME=	activesupport-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activesupport${RUBY_RAILS}-${RAILS_VERSION}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit of support libraries (part of Rails 5.2)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.7<2:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0.2<1.2:../../devel/ruby-concurrent-ruby
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo1>=1.1<2:../../time/ruby-tzinfo1
# minitest 5.4.3 is bundled with Ruby 2.2 and later.
#DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=5.1<6:../../devel/ruby-minitest

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	52
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
