# $NetBSD: Makefile,v 1.2 2010/08/03 06:31:45 obache Exp $

DISTNAME=	twitter-stream-0.1.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/voloko/twitter-stream
COMMENT=	Twitter realtime API client
#LICENSE=	# neither copyright nor restriction notice

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.8:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-roauth>=0.0.2:../../security/ruby-roauth

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
