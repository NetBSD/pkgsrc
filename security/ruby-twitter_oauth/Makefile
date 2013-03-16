# $NetBSD: Makefile,v 1.4 2013/03/16 12:52:10 obache Exp $

DISTNAME=	twitter_oauth-0.4.4
CATEGORIES=	security

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://github.com/moomerman/twitter_oauth
COMMENT=	Ruby client for the Twitter API using OAuth
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-oauth>=0.4.1:../../security/ruby-oauth

RUBY_JSON_REQD=	1.1.9

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/json.mk"
.include "../../mk/bsd.pkg.mk"
