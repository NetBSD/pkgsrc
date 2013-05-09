# $NetBSD: Makefile,v 1.1 2013/05/09 15:53:33 mef Exp $

DISTNAME=	twitter-4.6.2
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://sferik.github.io/twitter/
COMMENT=	Ruby interface to the Twitter API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-simple_oauth>=0.1.4:../../security/ruby-simple_oauth
OVERRIDE_GEMSPEC+=	simple_oauth>=0.1.4
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0.0:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.8<0.10:../../www/ruby-faraday

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
