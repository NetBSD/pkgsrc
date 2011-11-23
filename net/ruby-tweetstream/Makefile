# $NetBSD: Makefile,v 1.4 2011/11/23 05:32:59 taca Exp $

DISTNAME=	tweetstream-1.0.5
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/intridea/tweetstream
COMMENT=	RubyGem to access the Twitter Stream API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-daemons-[0-9]*:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-stream-[0-9]*:../../net/ruby-twitter-stream

RUBY_JSON_REQD=	0

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
