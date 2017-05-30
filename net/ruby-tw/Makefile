# $NetBSD: Makefile,v 1.19 2017/05/30 15:13:03 taca Exp $

DISTNAME=	tw-1.0.12
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://shokai.github.io/tw/
COMMENT=	CUI Twitter Client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-args_parser>=0.2.0:../../misc/ruby-args_parser
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=2.4.2:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-parallel>=0.9.1:../../misc/ruby-parallel
DEPENDS+=	${RUBY_PKGPREFIX}-rainbow>=2.0.0:../../misc/ruby-rainbow
DEPENDS+=	${RUBY_PKGPREFIX}-twitter>=5.15.0:../../net/ruby-twitter
DEPENDS+=	${RUBY_PKGPREFIX}-userstream>=1.4.0:../../net/ruby-userstream

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
