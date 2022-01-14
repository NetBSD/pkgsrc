# $NetBSD: Makefile,v 1.25 2022/01/14 15:51:50 taca Exp $

DISTNAME=	tw-1.3.1
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://shokai.github.io/tw/
COMMENT=	CUI Twitter Client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-args_parser>=0.2.0:../../misc/ruby-args_parser
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=2.4.3:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-parallel>=1.12.0:../../misc/ruby-parallel
DEPENDS+=	${RUBY_PKGPREFIX}-rainbow>=3.0.0:../../misc/ruby-rainbow
DEPENDS+=	${RUBY_PKGPREFIX}-twitter>=6.2.0:../../net/ruby-twitter
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.5.4:../../security/ruby-oauth

OVERRIDE_GEMSPEC+=	json>=${RUBY_JSON_VER}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
