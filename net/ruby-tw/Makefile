# $NetBSD: Makefile,v 1.12 2014/03/09 15:26:15 tsutsui Exp $

DISTNAME=	tw-1.0.8
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://shokai.github.io/tw/
COMMENT=	CUI Twitter Client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-args_parser>=0.2.0:../../misc/ruby-args_parser
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=2.4.2:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-parallel>=0.9.1:../../misc/ruby-parallel
DEPENDS+=	${RUBY_PKGPREFIX}-rainbow>=2.0.0:../../misc/ruby-rainbow
DEPENDS+=	${RUBY_PKGPREFIX}-twitter>=5.6.0:../../net/ruby-twitter
DEPENDS+=	${RUBY_PKGPREFIX}-userstream>=1.2.0:../../net/ruby-userstream

RUBY_VERSION_SUPPORTED=	200 193
RUBY_JSON_REQD=	1.7.0

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
