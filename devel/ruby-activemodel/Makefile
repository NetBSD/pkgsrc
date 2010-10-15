# $NetBSD: Makefile,v 1.2 2010/10/15 11:41:45 taca Exp $

DISTNAME=	activemodel-3.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails)
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=3.0.1:../../devel/ruby-activesupport3
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.4.1:../../devel/ruby-i18n

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
