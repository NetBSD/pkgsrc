# $NetBSD: Makefile,v 1.1 2024/08/20 02:54:00 wen Exp $

DISTNAME=	reline-0.5.9
CATEGORIES=	devel

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/reline/
COMMENT=	Alternative GNU Readline or Editline implementation by pure Ruby
LICENSE=	2-clause-bsd OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-io-console>=0.5:../../devel/ruby-io-console

#USE_LANGUAGES=	c

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
