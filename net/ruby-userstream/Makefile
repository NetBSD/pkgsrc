# $NetBSD: Makefile,v 1.7 2016/03/16 15:15:18 tsutsui Exp $

DISTNAME=	userstream-1.4.0
PKGREVISION=	4
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/mitukiii/userstream
COMMENT=	Simple twitter userstream library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hashie>=1.2.0:../../misc/ruby-hashie
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.7:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-yajl>=1.1.0:../../textproc/ruby-yajl

OVERRIDE_GEMSPEC+=	hashie>=1.2.0
OVERRIDE_GEMSPEC+=	yajl-ruby>=1.1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
