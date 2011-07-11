# $NetBSD: Makefile,v 1.8 2011/07/11 11:58:35 obache Exp $

DISTNAME=	twitter-stream-0.1.14
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/voloko/twitter-stream
COMMENT=	Twitter realtime API client
#LICENSE=	# neither copyright nor restriction notice

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.8:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-simple_oauth>=0.1.4:../../security/ruby-simple_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.5.1:../../www/ruby-http_parser.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
