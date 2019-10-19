# $NetBSD: Makefile,v 1.5 2019/10/19 08:12:15 tsutsui Exp $

DISTNAME=	diva-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/diva
COMMENT=	Implementation of expression for handling things
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.5.2<2.8:../../net/ruby-addressable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
