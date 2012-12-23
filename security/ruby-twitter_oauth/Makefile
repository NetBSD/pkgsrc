# $NetBSD: Makefile,v 1.3 2012/12/23 07:09:36 obache Exp $

DISTNAME=	twitter_oauth-0.4.4
CATEGORIES=	security

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/moonmerman/twitter-oauth
COMMENT=	Ruby client for the Twitter API using OAuth
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.1:../../security/ruby-oauth

RUBY_JSON_REQD=	1.1.9

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
