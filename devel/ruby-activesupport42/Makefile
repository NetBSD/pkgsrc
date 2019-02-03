# $NetBSD: Makefile,v 1.6 2019/02/03 15:09:21 taca Exp $

DISTNAME=	activesupport-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activesupport${RUBY_RAILS}-${RAILS_VERSION}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit of support libraries (part of Rails 4.2)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-i18n12>=0.7:../../devel/ruby-i18n12
DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.3.4:../../misc/ruby-thread_safe
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo1>=1.1:../../time/ruby-tzinfo1
# minitest 5.4.3 is bundlerd with Ruby 2.2 and later.
#DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=5.1:../../devel/ruby-minitest

RUBY_RAILS_ACCEPTED=	42
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
