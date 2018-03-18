# $NetBSD: Makefile,v 1.5 2018/03/18 14:21:20 taca Exp $

DISTNAME=	activesupport-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activesupport${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit of support libraries (part of Rails 4.2)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.7:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.3.4:../../misc/ruby-thread_safe
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=1.1:../../time/ruby-tzinfo
# minitest 5.4.3 is bundlerd with Ruby 2.2 and later.
#DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=5.1:../../devel/ruby-minitest

RUBY_RAILS_ACCEPTED=	42
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
