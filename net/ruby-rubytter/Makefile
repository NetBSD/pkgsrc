# $NetBSD: Makefile,v 1.2 2010/05/16 11:52:35 obache Exp $

DISTNAME=	rubytter-1.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/jugyo/rubytter
COMMENT=	Simple twitter library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.3.6:../../security/ruby-oauth
DEPENDS+=	${RUBY_PKGPREFIX}-json>=1.1.3:../../textproc/ruby-json

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
