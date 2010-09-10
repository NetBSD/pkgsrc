# $NetBSD: Makefile,v 1.4 2010/09/10 07:39:14 taca Exp $

DISTNAME=	twitter-stream-0.1.8
CATEGORIES=	net

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/voloko/twitter-stream
COMMENT=	Twitter realtime API client
#LICENSE=	# neither copyright nor restriction notice

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.8:../../devel/ruby-eventmachine
DEPENDS+=	${RUBY_PKGPREFIX}-roauth>=0.0.2:../../security/ruby-roauth

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
