# $NetBSD: Makefile,v 1.2 2017/02/09 13:04:27 tsutsui Exp $

DISTNAME=	slack-api-1.3.0
CATEGORIES=	net
PKGREVISION=	1

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/aki017/slack-ruby-gem
COMMENT=	Ruby wrapper for the Slack API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0.3:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.11:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-faraday_middleware>=0.10.1:../../www/ruby-faraday_middleware
DEPENDS+=	${RUBY_PKGPREFIX}-faye-websocket>=0.9.2:../../www/ruby-faye-websocket

OVERRIDE_GEMSPEC+=	faraday_middleware>=0.10.1
OVERRIDE_GEMSPEC+=	faye-websocket>=0.9.2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
