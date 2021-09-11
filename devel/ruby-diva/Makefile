# $NetBSD: Makefile,v 1.9 2021/09/11 09:47:00 tsutsui Exp $

DISTNAME=	diva-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/diva
COMMENT=	Implementation of expression for handling things
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.5.2<3.0:../../net/ruby-addressable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
