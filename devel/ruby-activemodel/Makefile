# $NetBSD: Makefile,v 1.9 2011/12/14 16:21:53 taca Exp $

DISTNAME=	activemodel-${RUBY_RAILS_VERSION}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5.0:../../devel/ruby-i18n_05

RUBY_RAILS_SUPPORTED=	3

OVERRIDE_GEMSPEC+=	builder>=2.1.2 i18n>=0.5.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
