# $NetBSD: Makefile,v 1.1.1.1 2010/05/26 10:58:00 obache Exp $

DISTNAME=	tweetstream-1.0.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/intridea/tweetstream
COMMENT=	RubyGem to access the Twitter Stream API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-daemons-[0-9]*:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-stream-[0-9]*:../../net/ruby-twitter-stream
DEPENDS+=	${RUBY_PKGPREFIX}-json-[0-9]*:../../textproc/ruby-json

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
