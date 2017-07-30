# $NetBSD: Makefile,v 1.15 2017/07/30 22:32:20 wiz Exp $

DISTNAME=	twitter-stream-0.1.16
PKGREVISION=	2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/voloko/twitter-stream
COMMENT=	Twitter realtime API client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.8:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-simple_oauth>=0.1.4:../../security/ruby-simple_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.5.1:../../www/ruby-http_parser.rb

OVERRIDE_GEMSPEC+=	simple_oauth>=0.1.4
OVERRIDE_GEMSPEC+=	http_parser.rb>=0.5.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
