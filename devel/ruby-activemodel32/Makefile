# $NetBSD: Makefile,v 1.6 2018/03/18 14:21:20 taca Exp $

DISTNAME=	activemodel-${RAILS_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-activemodel${RUBY_RAILS}-${RAILS_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 3.2)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder30>=3.0.0<3.1:../../textproc/ruby-builder30

RUBY_RAILS_ACCEPTED=	32
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
