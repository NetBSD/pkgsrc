# $NetBSD: Makefile,v 1.2 2024/12/09 14:09:11 taca Exp $

DISTNAME=	reline-0.5.12
CATEGORIES=	devel

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/reline/
COMMENT=	Alternative GNU Readline or Editline implementation by pure Ruby
LICENSE=	2-clause-bsd OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-io-console>=0.5:../../devel/ruby-io-console

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
