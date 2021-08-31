# $NetBSD: Makefile,v 1.8 2021/08/31 15:35:48 taca Exp $

DISTNAME=	diva-1.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/diva
COMMENT=	Implementation of expression for handling things
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.5.2:../../net/ruby-addressable

USE_LANGUAGES=	# none

GEMSPEC_OVERRIDE+=	addressable>=2.5.2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
