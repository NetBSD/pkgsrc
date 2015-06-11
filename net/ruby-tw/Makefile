# $NetBSD: Makefile,v 1.16 2015/06/11 17:38:27 taca Exp $

DISTNAME=	tw-1.0.9
PKGREVISION=	1
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
DEPENDS+=	${RUBY_PKGPREFIX}-userstream>=1.4.0:../../net/ruby-userstream

RUBY_JSON_REQD=	1.7.0

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
