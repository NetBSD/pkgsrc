# $NetBSD: Makefile,v 1.3 2017/03/20 16:21:42 tsutsui Exp $

DISTNAME=	slack-api-1.4.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/aki017/slack-ruby-gem
COMMENT=	Ruby wrapper for the Slack API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0.3:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.11:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-faraday_middleware>=0.10.0:../../www/ruby-faraday_middleware
DEPENDS+=	${RUBY_PKGPREFIX}-faye-websocket>=0.10.6:../../www/ruby-faye-websocket

OVERRIDE_GEMSPEC+=	faraday_middleware>=0.10.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
