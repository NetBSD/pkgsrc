# $NetBSD: Makefile,v 1.3 2011/11/08 09:08:21 obache Exp $

DISTNAME=	tweetstream-1.0.5
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/intridea/tweetstream
COMMENT=	RubyGem to access the Twitter Stream API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-daemons-[0-9]*:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-stream-[0-9]*:../../net/ruby-twitter-stream
DEPENDS+=	${RUBY_PKGPREFIX}-json-[0-9]*:../../textproc/ruby-json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
