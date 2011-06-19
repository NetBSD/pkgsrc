# $NetBSD: Makefile,v 1.6 2011/06/19 02:52:44 taca Exp $

DISTNAME=	rubytter-1.4.2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/jugyo/rubytter
COMMENT=	Simple twitter library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.3.6:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-json>=1.1.3:../../textproc/ruby-json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
