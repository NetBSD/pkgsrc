# $NetBSD: Makefile,v 1.1 2017/04/14 08:00:26 minskim Exp $

DISTNAME=	activesupport-${RUBY_RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit of support libraries (part of Rails 4.2)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.7:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=5.1:../../devel/ruby-minitest
DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0.3.4:../../misc/ruby-thread_safe
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=1.1:../../time/ruby-tzinfo

RUBY_RAILS_SUPPORTED=	42
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
