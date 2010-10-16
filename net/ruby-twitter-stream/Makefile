# $NetBSD: Makefile,v 1.5 2010/10/16 05:09:36 obache Exp $

DISTNAME=	twitter-stream-0.1.10
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/voloko/twitter-stream
COMMENT=	Twitter realtime API client
#LICENSE=	# neither copyright nor restriction notice

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.8:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-roauth>=0.0.2:../../security/ruby-roauth

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
