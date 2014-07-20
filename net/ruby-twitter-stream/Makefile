# $NetBSD: Makefile,v 1.13 2014/07/20 01:16:48 obache Exp $

DISTNAME=	twitter-stream-0.1.16
PKGREVISION=	2
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/voloko/twitter-stream
COMMENT=	Twitter realtime API client
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.8:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-simple_oauth>=0.1.4:../../security/ruby-simple_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.5.1:../../www/ruby-http_parser.rb

OVERRIDE_GEMSPEC+=	simple_oauth>=0.1.4
OVERRIDE_GEMSPEC+=	http_parser.rb>=0.5.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
