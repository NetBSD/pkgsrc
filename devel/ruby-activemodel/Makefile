# $NetBSD: Makefile,v 1.10 2012/03/18 05:23:30 taca Exp $

DISTNAME=	activemodel-${RUBY_RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 3.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5.0<0.6:../../devel/ruby-i18n_05

RUBY_RAILS_SUPPORTED=	3

OVERRIDE_GEMSPEC+=	builder>=2.1.2 i18n>=0.5.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
