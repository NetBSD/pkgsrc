# $NetBSD: Makefile,v 1.1.1.1 2012/03/18 06:46:44 taca Exp $

DISTNAME=	activemodel-${RUBY_RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 3.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.0.0<3.1:../../textproc/ruby-builder

RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
