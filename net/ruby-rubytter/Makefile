# $NetBSD: Makefile,v 1.5 2010/09/10 07:38:13 taca Exp $

DISTNAME=	rubytter-1.4.1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/jugyo/rubytter
COMMENT=	Simple twitter library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.3.6:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-json>=1.1.3:../../textproc/ruby-json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
