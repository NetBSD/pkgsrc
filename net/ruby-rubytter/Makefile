# $NetBSD: Makefile,v 1.10 2017/07/30 22:32:20 wiz Exp $

DISTNAME=	rubytter-1.5.1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jugyo/rubytter
COMMENT=	Simple twitter library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.3.6:../../security/ruby-oauth

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
