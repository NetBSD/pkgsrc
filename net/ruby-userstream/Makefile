# $NetBSD: Makefile,v 1.4 2015/02/04 14:06:50 taca Exp $

DISTNAME=	userstream-1.4.0
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/mitukiii/userstream
COMMENT=	Simple twitter userstream library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hashie1>=1.2.0<2.0.0:../../misc/ruby-hashie1
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.7:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-yajl>=1.1.0<1.2.0:../../textproc/ruby-yajl

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
