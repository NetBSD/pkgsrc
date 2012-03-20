# $NetBSD: Makefile,v 1.5 2012/03/20 14:03:50 taca Exp $

DISTNAME=	tweetstream-1.1.4
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/intridea/tweetstream
COMMENT=	RubyGem to access the Twitter Stream API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.1<2:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-stream>=0.1.14<0.2:../../net/ruby-twitter-stream

RUBY_JSON_REQD=	0

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
