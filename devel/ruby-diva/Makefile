# $NetBSD: Makefile,v 1.7 2020/03/23 15:34:38 taca Exp $

DISTNAME=	diva-1.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/diva
COMMENT=	Implementation of expression for handling things
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.5.2<2.8:../../net/ruby-addressable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
