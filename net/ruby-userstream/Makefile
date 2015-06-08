# $NetBSD: Makefile,v 1.5 2015/06/08 16:00:18 taca Exp $

DISTNAME=	userstream-1.4.0
PKGREVISION=	2
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/mitukiii/userstream
COMMENT=	Simple twitter userstream library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hashie1>=1.2.0<2.0.0:../../misc/ruby-hashie1
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.7:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-yajl>=1.1.0<1.3.0:../../textproc/ruby-yajl

OVERRIDE_GEMSPEC+=	yajl>=1.1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
