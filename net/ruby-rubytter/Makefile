# $NetBSD: Makefile,v 1.11 2022/08/29 14:20:56 wiz Exp $

DISTNAME=	rubytter-1.5.1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jugyo/rubytter
COMMENT=	Simple twitter library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.3.6:../../security/ruby-oauth

RUBY_VERSIONS_INCOMPATIBLE=	26 # ruby-oauth

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
