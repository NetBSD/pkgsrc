# $NetBSD: Makefile,v 1.12 2013/02/12 15:30:42 taca Exp $

DISTNAME=	activemodel-${RUBY_RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 3.0)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5.0<0.6:../../devel/ruby-i18n_05

RUBY_RAILS_SUPPORTED=	3
RUBY_RAILS_STRICT_DEP=	yes

OVERRIDE_GEMSPEC+=	builder>=2.1.2 i18n>=0.5.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
