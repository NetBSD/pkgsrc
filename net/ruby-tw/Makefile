# $NetBSD: Makefile,v 1.10 2014/01/17 08:41:05 obache Exp $

DISTNAME=	tw-0.5.2
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://shokai.github.io/tw/
COMMENT=	CUI Twitter Client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-args_parser>=0.2.0:../../misc/ruby-args_parser
DEPENDS+=	${RUBY_PKGPREFIX}-parallel>=0.8.2:../../misc/ruby-parallel
DEPENDS+=	${RUBY_PKGPREFIX}-rainbow>=1.1.4:../../misc/ruby-rainbow
DEPENDS+=	${RUBY_PKGPREFIX}-twitter>=4.4.0:../../net/ruby-twitter
DEPENDS+=	${RUBY_PKGPREFIX}-userstream>=1.2.0:../../net/ruby-userstream

RUBY_VERSION_SUPPORTED=	200 193
RUBY_JSON_REQD=	1.7.0

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
