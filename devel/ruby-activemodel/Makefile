# $NetBSD: Makefile,v 1.5 2011/03/25 08:44:44 taca Exp $

DISTNAME=	activemodel-${RUBY_RAILS3_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails)
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.4<1:../../devel/ruby-i18n

RUBY_RAILS=	3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
