# $NetBSD: Makefile,v 1.5.4.1 2018/07/14 09:22:39 bsiegert Exp $

DISTNAME=	activesupport-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activesupport${RUBY_RAILS}-${RAILS_VERSION}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit of support libraries (part of Rails 3.2)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.6:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json

RUBY_RAILS_ACCEPTED=	32
RUBY_RAILS_STRICT_DEP=	yes

OVERRIDE_GEMSPEC+=	i18n>=0.6

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
