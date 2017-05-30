# $NetBSD: Makefile,v 1.9 2017/05/30 15:13:03 taca Exp $

DISTNAME=	rubytter-1.5.1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/jugyo/rubytter
COMMENT=	Simple twitter library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.3.6:../../security/ruby-oauth

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
