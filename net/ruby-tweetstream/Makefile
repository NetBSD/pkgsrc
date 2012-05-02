# $NetBSD: Makefile,v 1.6 2012/05/02 12:34:56 obache Exp $

DISTNAME=	tweetstream-1.1.5
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/intridea/tweetstream
COMMENT=	RubyGem to access the Twitter Stream API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.1<2:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-stream>=0.1.14<1:../../net/ruby-twitter-stream
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.3<2:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
