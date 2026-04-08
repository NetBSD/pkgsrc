# $NetBSD: Makefile,v 1.8 2026/04/08 14:29:34 taca Exp $

DISTNAME=	slack-api-1.6.1
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/aki017/slack-ruby-gem
COMMENT=	Ruby wrapper for the Slack API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0.3:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-faraday_middleware>=0.10.0:../../www/ruby-faraday_middleware
DEPENDS+=	${RUBY_PKGPREFIX}-faye-websocket>=0.10.6:../../www/ruby-faye-websocket

RUBY_VERSIONS_ACCEPTED=	33 34

OVERRIDE_GEMSPEC+=	faraday_middleware>=0.10.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
