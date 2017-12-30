# $NetBSD: Makefile,v 1.1 2017/12/30 04:38:12 tsutsui Exp $

DISTNAME=	diva-0.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/diva
COMMENT=	Implementation of expression for handling things
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.5<2.6:../../net/ruby-addressable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
