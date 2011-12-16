# $NetBSD: Makefile,v 1.1.1.1 2011/12/16 12:21:23 taca Exp $

DISTNAME=	activemodel-${RUBY_RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 3.1)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.0.0<3.1:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.6<1:../../devel/ruby-i18n

RUBY_RAILS_SUPPORTED=	31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
